--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

require "UnLua"

local BlueprintEnum = require "Core.Enum.BlueprintEnum"

print("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX")
local BP_GameModeBase_Lua_C = Class()

--function BP_GameModeBase_Lua_C:Initialize(Initializer)
--end

--function BP_GameModeBase_Lua_C:UserConstructionScript()
--end

function BP_GameModeBase_Lua_C:execute(command)
    print("FFFFFFFFFFFFFFFFFFFFFFFFUUUUUUUUUUUUUUUUUUUUUCCCCCCCCCCCCCCC")
    print(command)
end

function BP_GameModeBase_Lua_C:ReceiveBeginPlay()
    self.CallbackFunction:Bind(self, BP_GameModeBase_Lua_C.execute)
    local UMG_Main_C = UE4.UClass.Load(BlueprintEnum.UMG.UMG_Main)
    local UMG_Main = UE4.UWidgetBlueprintLibrary.Create(self, UMG_Main_C)
    UMG_Main:AddToViewport()
    self.Overridden.ReceiveBeginPlay(self)
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
