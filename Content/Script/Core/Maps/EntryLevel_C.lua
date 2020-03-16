--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

require "UnLua"
local BlueprintEnum = require "Core.Enum.BlueprintEnum"

local EntryLevel_C = Class()

--function EntryLevel_C:Initialize(Initializer)
--end

--function EntryLevel_C:UserConstructionScript()
--end

function EntryLevel_C:ReceiveBeginPlay()
    -- Login UMG
    local UMG_Login_C = UE4.UClass.Load(BlueprintEnum.UMG.UMG_Login)
    local UMG_Login = UE4.UWidgetBlueprintLibrary.Create(self, UMG_Login_C)
    UMG_Login:AddToViewport()
end

--function EntryLevel_C:ReceiveEndPlay()
--end

-- function EntryLevel_C:ReceiveTick(DeltaSeconds)
-- end

--function EntryLevel_C:ReceiveAnyDamage(Damage, DamageType, InstigatedBy, DamageCauser)
--end

--function EntryLevel_C:ReceiveActorBeginOverlap(OtherActor)
--end

--function EntryLevel_C:ReceiveActorEndOverlap(OtherActor)
--end

return EntryLevel_C
