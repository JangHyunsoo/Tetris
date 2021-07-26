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
	double m_fSpeed; // 떨어지는 딜레이
	int m_iRot; // 회전
	char m_cType; // 모양
	POSITION m_tGamePos;
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

	void SetGamePos(POSITION tPos) {
		m_tGamePos = tPos;
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

	POSITION GetGamePos() {
		return m_tGamePos;
	}

public:
	void TurnLeft() {
		m_iRot = abs((m_iRot + 1) % 4);
	}
	
	void TurnRight() {
		m_iRot = abs((m_iRot - 1) % 4);
	}
	
private:
	void AddDelay(double fDelay) {
		m_fDelay += fDelay;
	}
	void MoveGame(int x, int y) {
		m_tGamePos.x += x;
		m_tGamePos.y += y;
	}
	
public:
	void MakeOrigin(char cType);

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);
	virtual CCursorBlock* Clone();
};
