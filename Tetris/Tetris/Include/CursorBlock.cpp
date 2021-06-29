#include "CursorBlock.h"
#include "Input.h"
#include "BlockDataBase.h"

CCursorBlock::CCursorBlock()
{
}

CCursorBlock::CCursorBlock(const CCursorBlock& obj) :
	CMoveObj(obj),
	m_fSpeed(obj.m_fSpeed),
	m_fDelay(obj.m_fDelay),
	m_iRot(obj.m_iRot),
	m_cType(obj.m_cType)

{
}

CCursorBlock::~CCursorBlock()
{
}

bool CCursorBlock::Init()
{
	SetPos(300.f, 300.f);
	SetSize(20.f, 20.f);
	SetSpeed(1.0f);
	SetDelay(0.0f);
	SetRotation(0);
	SetType('T');

	return true;
}

void CCursorBlock::Input(float fDeltaTime)
{
	CMoveObj::Input(fDeltaTime);
	if (GET_SINGE(CInput)->KeyDown("MoveLeft")) {
		Move(-20, 0);
		m_fDelay *= 0.9f;
	}

	if (GET_SINGE(CInput)->KeyDown("MoveRight")) {
		Move(20, 0);
		m_fDelay *= 0.9f;
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
		Move(0, 20);
		m_fDelay = 0;
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
	vector<POSITION> arrData = CBlockDataBase::GetData(m_cType)->GetData(m_iRot);

	for (int i = 0; i < arrData.size(); i++) {
		int x = m_tPos.x + (arrData[i].x * m_tSize.x);
		int y = m_tPos.y + (arrData[i].y * m_tSize.y);
		Rectangle(hDC, x, y, x + m_tSize.x, y + m_tSize.y);
	}

	//Rectangle(hDC, m_tPos.x, m_tPos.y, m_tPos.x + m_tSize.x, m_tPos.y + m_tSize.y);
}

CCursorBlock* CCursorBlock::Clone()
{
	return new CCursorBlock(*this);
}
