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

	return true;
}

void CInGameScene::Input(float fDeltaTime)
{
}

int CInGameScene::Update(float fDeltaTime)
{
	return 0;
}

int CInGameScene::LateUpdate(float fDeltaTime)
{
	return 0;
}

void CInGameScene::Collision(float fDeltaTime)
{
}

void CInGameScene::Render(HDC hDC, float fDeltaTime)
{
}
