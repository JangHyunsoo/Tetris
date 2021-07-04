#include "RuleManager.h"
#include "BlockDataBase.h"

CRuleManager::CRuleManager()
{
	memset(m_arrCell, false, sizeof(m_arrCell));
}

CRuleManager::~CRuleManager()
{
}

bool CRuleManager::Init() {

	return true;
}

void CRuleManager::SetCell(int x, int y, char cBlockType, int iRot)
{
	vector<POSITION> vecpos = CBlockDataBase::GetData(cBlockType)->GetData(iRot);

	for (int i = 0; i < vecpos.size(); i++) {
		m_arrCell[x + (int)vecpos[i].x][y + (int)vecpos[i].y] = true;
	}
}

bool CRuleManager::CheckMove(int x, int y, char cBlockType, int iRot)
{
	vector<POSITION> vecpos = CBlockDataBase::GetData(cBlockType)->GetData(iRot);
	
	for (int i = 0; i < vecpos.size(); i++) {
		if (!IsMap( x + (int)vecpos[i].x, y + (int)vecpos[i].y)) return false;
		if (m_arrCell[ x + (int)vecpos[i].x][ y + (int)vecpos[i].y]) return false;
	}

	return true;
}

void CRuleManager::Render(HDC hDC, float fDeltaTime)
{
	/*
	for (int x = 0; x < m_iWidth; x++) {
		for (int y = 0; y < m_iHeight; y++) {
			if (m_arrCell[x][y])
				BitBlt(hDC, x * 16, y * 16, x * 16 + 16, y * 16 + 16, ->GetDC(), 0, 0, SRCCOPY);
			else
				Rectangle(hDC, x * 16, y * 16, x * 16 + 16, y * 16 + 16);
		}
	}*/
}