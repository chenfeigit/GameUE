#pragma once

#include "CoreMinimal.h"
#include "Public/UnLua.h"

//
//DECLARE_DYNAMIC_DELEGATE_FourParams(Sender, int32, int32, int32m uint8*);

class GAMEUE_API FLuaProto
{
public:

	FLuaProto() { Instance = this; }

	~FLuaProto() { Instance = nullptr; }

	/**
	 * Send pack to server.
	 * ------------------------------------------------------------
	 * @LuaCallableFunction
	 * SendPack(int ProtoId, userdata Buffer, int32 Size)
	 * @param ProtoId	
	 * @param Buffer	
	 * @param Size		
	 * @return			
	 * ------------------------------------------------------------
	 */
	static int SendPack(lua_State* L);

	/**
	 * Get type name.
	 * ------------------------------------------------------------
	 * @LuaCallableFunction
	 * SendPack(int ProtoId, userdata Buffer, int32 Size)
	 * @param ProtoId
	 * @param Buffer
	 * @param Size
	 * @return
	 * ------------------------------------------------------------
	 */
	//static int GetTypeName(lua_State* L);

	//static void CreateTable(lua_State* L, luaL_Reg* FuncMapArray);

	void Setup(lua_State* L);

	//void CleanUp();

private:

	//void SendPack_Impl(int32 Remote, int32 Proto, int32 Size, uint8* Data);

	//void ReceivePack(int32 Proto, uint8* Data, int32 Size);

	//Sender PackSender;

	static FLuaProto* Instance;

};