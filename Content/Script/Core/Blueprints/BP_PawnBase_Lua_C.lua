--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

require "UnLua"

local BP_PawnBase_Lua_C = Class()

--function BP_PawnBase_Lua_C:Initialize(Initializer)
--end

--function BP_PawnBase_Lua_C:UserConstructionScript()
--end

function BP_PawnBase_Lua_C:ReceiveBeginPlay()
    self:K2_SetActorLocation(UE4.FVector(0.0, 0.0, 135.1))
end

-- function BP_PawnBase_Lua_C:ReceiveEndPlay()
-- end

-- function BP_PawnBase_Lua_C:ReceiveTick(DeltaSeconds)
-- end

--function BP_PawnBase_Lua_C:ReceiveAnyDamage(Damage, DamageType, InstigatedBy, DamageCauser)
--end

--function BP_PawnBase_Lua_C:ReceiveActorBeginOverlap(OtherActor)
--end

--function BP_PawnBase_Lua_C:ReceiveActorEndOverlap(OtherActor)
--end

return BP_PawnBase_Lua_C
