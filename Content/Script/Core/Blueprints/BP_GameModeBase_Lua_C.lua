--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

require "UnLua"

local BP_GameModeBase_Lua_C = Class()

--function BP_GameModeBase_Lua_C:Initialize(Initializer)
--end

--function BP_GameModeBase_Lua_C:UserConstructionScript()
--end

function BP_GameModeBase_Lua_C:ExecuteCommand(command)
    print("Execute GM Command Entry Function.")
    print(command)
end

function BP_GameModeBase_Lua_C:ReceiveBeginPlay()
    -- Bind GM command execute function
    self.CallbackFunction:Bind(self, BP_GameModeBase_Lua_C.ExecuteCommand)
end

--function BP_GameModeBase_Lua_C:ReceiveEndPlay()
--end

-- function BP_GameModeBase_Lua_C:ReceiveTick(DeltaSeconds)
-- end

--function BP_GameModeBase_Lua_C:ReceiveAnyDamage(Damage, DamageType, InstigatedBy, DamageCauser)
--end

--function BP_GameModeBase_Lua_C:ReceiveActorBeginOverlap(OtherActor)
--end

--function BP_GameModeBase_Lua_C:ReceiveActorEndOverlap(OtherActor)
--end

return BP_GameModeBase_Lua_C
