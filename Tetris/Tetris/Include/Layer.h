#pragma once
#include "Game.h"
#include "Obj.h"

class CLayer
{
private:
	friend class CScene;

public:
	CLayer();
	~CLayer();
private:
	class CScene* m_pScene; // contain Scene
	string m_strTag;
	int m_iZOrder;
	list<class CObj*> m_ObjList;

public:
	void SetTag(const string& strTag) {
		m_strTag = strTag;
	}

	void SetZOrder(int iZOrber) {
		m_iZOrder;
	}
	
	void SetScene(class CScene* pScene) {
		m_pScene = pScene;
	}

	string GetTag() const {
		return m_strTag;
	}

	int GetZOrder() const {
		return m_iZOrder;
	}

	class CScene* GetScene() const {
		return m_pScene;
	}

public:
	void Input(float fDeltaTime);
	int Update(float fDeltaTime);
	int LateUpdate(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Render(HDC hDC, float fDeltaTime);

};

