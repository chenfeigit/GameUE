--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

require "UnLua"
local BlueprintEnum = require "Core.Enum.BlueprintEnum"

local UMG_Login_C = Class()

--function UMG_Login_C:Initialize(Initializer)
--end

--function UMG_Login_C:PreConstruct(IsDesignTime)
--end

function UMG_Login_C:Construct()
    self.Button_Login.OnClicked:Add(self, UMG_Login_C.OnClicked_Button_Login)
end

function UMG_Login_C:OnClicked_Button_Login()
    print("Clicked")
    self:PlayAnimation(self.ButtonHidden)
    UE4.UGameplayStatics.OpenLevel(self, BlueprintEnum.Level.MainLevel)
end

--function UMG_Login_C:Tick(MyGeometry, InDeltaTime)
--end

return UMG_Login_C
