#include "CursorBlock.h"

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
	SetPos(100.f, 100.f);
	SetSize(100.f, 100.f);
	SetSpeed(100);
	SetDelay(0);

	return true;
}

void CCursorBlock::Input(float fDeltaTime)
{
	CMoveObj::Input(fDeltaTime);
	if (GetAsyncKeyState('A') & 0x8000) {
		Move(-100, 0);
	}

	if (GetAsyncKeyState('D') & 0x8000) {
		Move(100, 0);
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
	if (m_fDelay >= m_fSpeed) {
		Move(0, 10, fDeltaTime);
	}

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
