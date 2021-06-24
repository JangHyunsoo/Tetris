#include "CursorBlock.h"
#include "Input.h"

CCursorBlock::CCursorBlock()
{
}

CCursorBlock::CCursorBlock(const CCursorBlock& obj) :
	CMoveObj(obj)
{
}

CCursorBlock::~CCursorBlock()
{
}

bool CCursorBlock::Init()
{
	SetPos(300.f, 300.f);
	SetSize(20.f, 20.f);
	SetSpeed(100.0f);
	SetDelay(0.0f);

	return true;
}

void CCursorBlock::Input(float fDeltaTime)
{
	CMoveObj::Input(fDeltaTime);
	if (GET_SINGE(CInput)->KeyDown("MoveLeft")) {
		Move(-20, 0);
	}

	if (GET_SINGE(CInput)->KeyDown("MoveRight")) {
		Move(20, 0);
	}
}

int CCursorBlock::Update(float fDeltaTime)
{
	CMoveObj::Update(fDeltaTime);
	AddDelay(fDeltaTime);
	
	return 0;
}

int CCursorBlock::LateUpdate(float fDeltaTime)
{
	CMoveObj::LateUpdate(fDeltaTime);
	/*if (m_fDelay >= m_fSpeed) {
		Move(0, 20, fDeltaTime);
		m_fDelay = 0;
	}*/
	Move(0, 20, fDeltaTime);

	return 0;
}

void CCursorBlock::Collision(float fDeltaTime)
{
	CMoveObj::Collision(fDeltaTime);
}

void CCursorBlock::Render(HDC hDC, float fDeltaTime)
{
	CMoveObj::Render(hDC, fDeltaTime);
	Rectangle(hDC, m_tPos.x, m_tPos.y, m_tPos.x + m_tSize.x, m_tPos.y + m_tSize.y);
}

CCursorBlock* CCursorBlock::Clone()
{
	return new CCursorBlock(*this);
}
