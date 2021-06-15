#pragma once

#include "Game.h"

class CSceneManager
{
private:
	class CScene* m_pScene;
	class CScene* m_pNextScene;

public:
	bool Init();

public:
	template<typename T>
	T* CreateScene(SCENE_CREATE sc) {
		T* pScene = new T;

		if (!pScene->Init()) {
			SAFE_DELETE(pScene);
			return nullptr;
		}

		switch (sc)
		{
		case SCENE_CREATE::SC_CURRENT:
			SAFE_DELETE(m_pScene);
			m_pScene = pScene;
			break;
		case SCENE_CREATE::SC_NEXT:
			SAFE_DELETE(m_pNextScene);
			m_pNextScene = pScene;
			break;
		default:
			break;
		}

		return pScene;
	}

	DECLARE_SINGLE(CSceneManager)
};

