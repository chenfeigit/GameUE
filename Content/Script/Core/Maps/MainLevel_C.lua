--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

require "UnLua"
local BlueprintEnum = require "Core.Enum.BlueprintEnum"

local MainLevel_C = Class()

--function MainLevel_C:Initialize(Initializer)
--end

--function MainLevel_C:UserConstructionScript()
--end

function MainLevel_C:ReceiveBeginPlay()
    -- Login UMG
    local UMG_Main_C = UE4.UClass.Load(BlueprintEnum.UMG.UMG_Main)
    local UMG_Main = UE4.UWidgetBlueprintLibrary.Create(self, UMG_Main_C)
    UMG_Main:AddToViewport()
end

--function MainLevel_C:ReceiveEndPlay()
--end

-- function MainLevel_C:ReceiveTick(DeltaSeconds)
-- end

--function MainLevel_C:ReceiveAnyDamage(Damage, DamageType, InstigatedBy, DamageCauser)
--end

--function MainLevel_C:ReceiveActorBeginOverlap(OtherActor)
--end

--function MainLevel_C:ReceiveActorEndOverlap(OtherActor)
--end

return MainLevel_C
