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
	return false;
}

void CCursorBlock::Input(float fDeltaTime)
{
}

int CCursorBlock::Update(float fDeltaTime)
{
	return 0;
}

int CCursorBlock::LateUpdate(float fDeltaTime)
{
	return 0;
}

void CCursorBlock::Collision(float fDeltaTime)
{
}

void CCursorBlock::Render(HDC hDC, float fDeltaTime)
{
	Rectangle(hDC, m_tPos.x, m_tPos.y, m_tPos.x + m_tSize.x, m_tPos.y + m_tSize.y);
}