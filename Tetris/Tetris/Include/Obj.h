#pragma once

#include "Ref.h"

class CObj : 
	public CRef
{
protected:
	CObj();
	virtual ~CObj();

protected:
	string m_strTag;
	POSITION m_tPos;
	_SIZE m_tSize;

public:
	string GetTag() const {
		return m_strTag;
	}

	POSITION GetPosition() const {
		return m_tPos;
	}

	_SIZE GetSize() const {
		return m_tSize;
	}

public:
	void SetTag(const string& strTag) {
		m_strTag = strTag;
	}

	void SetPos(const POSITION& tPos) {
		m_tPos = tPos;
	}

	void SetPos(float x, float y) {
		m_tPos.x = x;
		m_tPos.y = y;
	}

	void SetPos(const POINT& tPos) {
		m_tPos = tPos;
	}

	void SetSize(const _SIZE& tSize) {
		m_tSize = tSize;
	}

	void SetSize(float x, float y) {
		m_tSize.x = x;
		m_tSize.y = y;
	}

	void SetSize(const POINT& tSize) {
		m_tSize = tSize;
	}

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);
};

