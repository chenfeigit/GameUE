
#include "LuaProto.h"

FLuaProto *FLuaProto::Instance(nullptr);

int FLuaProto::SendPack(lua_State* L)
{
	if (Instance != nullptr)
	{
		int d = lua_tonumber(L, 1);
		lua_pushnumber(L, d + 1);
		return 1;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("LuaProto instance is null."));
		return 1;
	}
}

static luaL_Reg LuaProtoMethods[] = {
	{"SendPack",						FLuaProto::SendPack},
	{NULL, NULL},
};

//int FLuaProto::GetTypeName(lua_State* L)
//{
//
//}
//
//void FLuaProto::CreateTable(lua_State* L, luaL_Reg* FuncMapArray)
//{
//
//}
//
void FLuaProto::Setup(lua_State* L)
{
	lua_newtable(L);
	luaL_Reg* funcs = LuaProtoMethods;
	for (; funcs->name; funcs++)
	{
		lua_pushstring(L, funcs->name);
		lua_pushcfunction(L, funcs->func);
		lua_rawset(L, -3);
	}
	lua_setglobal(L, "ProtoC");
}
//
//void FLuaProto::CleanUp()
//{
//
//}
//void FLuaProto::SendPack_Impl(int32 Remote, int32 Proto, int32 Size, uint8* Data)
//{
//
//}
//
//void FLuaProto::ReceivePack(int32 Proto, uint8* Data, int32 Size)
//{
//
//}

