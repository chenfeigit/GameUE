--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

require "UnLua"
local PlayerState = require "Core.Blueprints.BP_PlayerStateBase_Lua_C"
local GameMode = require "Core.Blueprints.BP_GameModeBase_Lua_C"

local UMG_Main_C = Class()

-- function UMG_Main_C:Initialize(Initializer)
-- end

--function UMG_Main_C:PreConstruct(IsDesignTime)
--end

function UMG_Main_C:Construct()
    self.ChatMsgButton.OnClicked:Add(self, UMG_Main_C.OnClicked_ChatMsgButton)
    self.ChatEmptyButton.OnClicked:Add(self, UMG_Main_C.OnClicked_ChatEmptyButton)
    self.ChatDetailSendButton.OnClicked:Add(self, UMG_Main_C.OnClicked_ChatDetailSendButton)

    self:InitTcpClient()
end

function UMG_Main_C:OnClicked_ChatMsgButton()
    print("Open Chat Detail UI")
    self.ChatMsgCanvas:SetVisibility(UE4.ESlateVisibility.Hidden)
    self.ChatDetailCanvas:SetVisibility(UE4.ESlateVisibility.Visible)
    self.ChatEmptyButton:SetVisibility(UE4.ESlateVisibility.Visible)
end

function UMG_Main_C:OnClicked_ChatEmptyButton()
    self.ChatDetailCanvas:SetVisibility(UE4.ESlateVisibility.Hidden)
    self.ChatEmptyButton:SetVisibility(UE4.ESlateVisibility.Hidden)
    self.ChatMsgCanvas:SetVisibility(UE4.ESlateVisibility.Visible)
end

function UMG_Main_C:OnClicked_ChatDetailSendButton()
    local MsgTxt = self.ChatDetailInputBox:GetText()
    if MsgTxt == "" then
        return
    end

    self:SendMsgToServer(MsgTxt)
    local PlayerMsgList = PlayerState.MsgList
    PlayerMsgList[#PlayerMsgList+1] = MsgTxt
    local AllPlayerMsg = ""
    for _, Msg in ipairs(PlayerMsgList) do
        AllPlayerMsg = AllPlayerMsg.."\n"..Msg
    end
    self.ChatDetailBox:SetText(AllPlayerMsg)
    self.ChatDetailInputBox:SetText("")
end

function UMG_Main_C:SendMsgToServer(Message)
    local TcpClient = self:GetTcpClient()
    TcpClient:SocketSend(Message)
end

function UMG_Main_C:GetGameUEInstance()
    return UE4.UGameplayStatics.GetGameInstance(self)
end

function UMG_Main_C:GetTcpClient()
    local GameUEInstance = self:GetGameUEInstance()
    return GameUEInstance:GetTcpClient()
end

function UMG_Main_C:InitTcpClient()
    local TcpClient = self:GetTcpClient()
    TcpClient:CreateSocket("127.0.0.1", 4399)
    TcpClient:SocketSend("Init")
    TcpClient:SocketReceive()
end

--function UMG_Main_C:Tick(MyGeometry, InDeltaTime)
--end

return UMG_Main_C
