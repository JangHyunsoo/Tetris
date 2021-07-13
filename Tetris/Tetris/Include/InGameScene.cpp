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
	
	GET_SINGE(CRuleManager)->SetBlockSize(32);

	CLayer* pLayer = FindLayer("UI");
	GET_SINGE(CRuleManager)->CreateHold(POSITION(400, 32), pLayer);
	GET_SINGE(CRuleManager)->CreateQueue(POSITION(400, 200), pLayer);

	pLayer = FindLayer("Default");
	GET_SINGE(CRuleManager)->StartGame(POSITION(32, 32), pLayer);

	return true;
}