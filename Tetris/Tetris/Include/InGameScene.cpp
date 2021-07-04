#include "InGameScene.h"
#include "CursorBlock.h"

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

	CObj::CreatePrototype<CCursorBlock>("CursorBlock");

	CObj* pBlock = CObj::CreateCloneObj("CursorBlock", "block", pLayer);

	SAFE_RELEASE(pBlock);

	return true;
}