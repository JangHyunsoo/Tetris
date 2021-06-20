#pragma once
#include "MoveObj.h"

class CCursorBlock :
    public CMoveObj
{
private:
	friend class CObj;
public:
	CCursorBlock();
	CCursorBlock(const CCursorBlock& obj);
    ~CCursorBlock();
private:
	double m_fDelay;
	double m_fSpeed;
public:
	void SetSpeed(double fSpeed) {
		m_fSpeed = fSpeed;
	}

	void SetDelay(double fDelay) {
		m_fDelay = fDelay;
	}

	double GetSpeed() const {
		return m_fSpeed;
	}

	double GetDelay() const {
		return m_fDelay;
	}

private:
	void AddDelay(double fDelay) {
		m_fDelay += fDelay;
	}
	
public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);
	virtual CCursorBlock* Clone();

};

