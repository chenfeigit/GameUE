
#include "LuaProto.h"
#include "Public/UnLuaBase.h"

bool FLuaProto::SendPack_Impl(int32 Remote, int32 ProtoId, int32 Size, uint8* Data)
{/*
	TcpSender.SocketSend("Hello from LuaProto");*/
	return true;
}

FLuaProto *FLuaProto::Instance(nullptr);

//SendPack(int32 Remote, int32 ProtoId, int32 Size, userdata Buffer)
int FLuaProto::SendPack(lua_State* L)
{
	if (!Instance) 
	{
		UE_LOG(LogUnLua, Warning, TEXT("LuaProto not instantiated!"));
		lua_pushnil(L);
		return 1;
	}

	int NumParams = lua_gettop(L);
	if (NumParams != 2 && NumParams != 4) 
	{
		UE_LOG(LogUnLua, Warning, TEXT("%s: Invalid parameters!"), ANSI_TO_TCHAR(__FUNCTION__));
		lua_pushnil(L);
		return 1;
	}

	int32 Remote = UnLua::Get(L, 1, UnLua::TType<int32>());
	int32 ProtoId = UnLua::Get(L, 2, UnLua::TType<int32>());
	int32 Size = 0;
	uint8* Buffer = nullptr;
	if (NumParams == 4)
	{
		Size = UnLua::Get(L, 3, UnLua::TType<int32>());
		Buffer = UnLua::Get(L, 4, UnLua::TType<uint8*>());
	}

	bool Result = Instance->SendPack_Impl(Remote, ProtoId, Size, Buffer);
	if (!Result)
	{
		lua_pushnil(L);
	}
	else
	{
		UnLua::Push(L, 1);
	}
	return 1;
}

static luaL_Reg LuaProtoMethods[] = {
	{"SendPack",						FLuaProto::SendPack},
	{NULL, NULL},
};

//int FLuaProto::GetTypeName(lua_State* L)
//{
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

	//TcpSender.CreateSocket("127.0.0.1", 4399);
	//TcpSender.SocketReceive();
}

void FLuaProto::SetupTcpTransport()
{

	//TSharedPtr<FInternetAddr> InternetAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	//InternetAddress->SetIp(IPAddress.Value);
	//InternetAddress->SetPort(PortNumber);
	//FIPv4Endpoint EndPoint("d", 4399);
	//TcpTransport = new FTcpMessageTransport()
}

void FLuaProto::CleanUp()
{
	//TcpSender.ThreadEnd();
}
//
//void FLuaProto::CleanUp()
//{
//
//}

//void FLuaProto::ReceivePack(int32 Proto, uint8* Data, int32 Size)
//{
//
//}

