#include "SceneManager.h"
#include "InGameScene.h"

DEFINITION_SINGLE(CSceneManager)

CSceneManager::CSceneManager() : m_pScene(nullptr), m_pNextScene(nullptr){

}

CSceneManager::~CSceneManager() {
	SAFE_DELETE(m_pScene);
	SAFE_DELETE(m_pNextScene);
}

bool CSceneManager::Init() {
	CreateScene<CInGameScene>(SCENE_CREATE::SC_CURRENT);
	
	return true;
}
