#pragma once
#include "MoveObj.h"
class CCursorBlock :
    public CMoveObj
{
private:
	CCursorBlock();
	CCursorBlock(const CCursorBlock& obj);
    ~CCursorBlock();
public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);
};

