#include "InGameScene.h"
#include "CursorBlock.h"
#include "RuleManager.h"

CInGameScene::CInGameScene()
{
}

CInGameScene::~CInGameScene()
{
}

bool CInGameScene::Init()
{
	if (!CScene::Init())
		return false;

	CLayer* pLayer = FindLayer("Default");
	GET_SINGE(CRuleManager)->StartGame(POSITION(32, 32), 32, pLayer);
	
	pLayer = FindLayer("UI");
	GET_SINGE(CRuleManager)->CreateHold(POSITION(400, 32), pLayer);

	return true;
}