#pragma once
#include "Game.h"

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
};

