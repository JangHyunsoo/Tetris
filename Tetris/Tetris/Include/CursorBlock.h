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
	int m_iRot;
	char m_cType;
	POSITION m_tLocalPos;
public:
	void SetSpeed(double fSpeed) {
		m_fSpeed = fSpeed;
	}

	void SetDelay(double fDelay) {
		m_fDelay = fDelay;
	}
	
	void SetRotation(int iRot) {
		m_iRot = iRot;
	}

	void SetType(char cType) {
		m_cType = cType;
	}

	double GetSpeed() const {
		return m_fSpeed;
	}

	double GetDelay() const {
		return m_fDelay;
	}

	int GetRotation() const {
		return m_iRot;
	}

	char GetType() const {
		return m_cType;
	}

public:
	void TurnLeft() {
		m_iRot++;
	}
	
	void TurnRight() {
		m_iRot--;
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
