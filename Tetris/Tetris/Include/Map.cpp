#include "Map.h"
#include "BlockDataBase.h"

CMap::CMap() {

}

CMap::CMap(const CMap& obj) :
	CStaticObj(obj)
{
	memset(m_arrCell, false, sizeof(m_arrCell));
}


CMap::~CMap()
{
}

void CMap::SetCell(int x, int y, bool bValue)
{
	m_arrCell[y][x] = bValue;
}

bool CMap::GetCell(int x, int y)
{
	return m_arrCell[y][x];
}

bool CMap::Init()
{
	SetPos(100, 100);
	SetTexture("Gray", L"Gray.bmp");

	return true;
}

void CMap::SetBlock(int x, int y, char cBlockType, int iRot)
{
	vector<POSITION> vecpos = CBlockDataBase::GetData(cBlockType)->GetData(iRot);

	for (int i = 0; i < vecpos.size(); i++) {
		m_arrCell[x + (int)vecpos[i].x][y + (int)vecpos[i].y] = true;
	}
}

bool CMap::CheckMove(int x, int y, char cBlockType, int iRot) // vector<pair<int, int>> 
{
	vector<POSITION> vecpos = CBlockDataBase::GetData(cBlockType)->GetData(iRot);

	for (int i = 0; i < vecpos.size(); i++) {
		if (!IsMap(x + (int)vecpos[i].x, y + (int)vecpos[i].y)) return false;
		if (m_arrCell[x + (int)vecpos[i].x][y + (int)vecpos[i].y]) return false;
	}

	return true;
}

void CMap::BreakLine(int y)
{
	for (int i = y; i > 0; i--) {
		for (int j = 0; j < m_iWidth; j++) {
			m_arrCell[j][i] = m_arrCell[j][i - 1];
		}
	}

	for (int i = 0; i < m_iWidth; i++) {
		m_arrCell[i][0] = false;
	}
}

bool CMap::IsMap(int x, int y)
{
	return x < m_iWidth && y < m_iHeight && x >= 0 && y >= 0;
}

bool CMap::CheckLine(int y)
{
	if (!IsMap(0, y)) return false;

	for (int i = 0; i < m_iWidth; i++) {
		if (!m_arrCell[i][y]) return false;
	}
	return true;
}

void CMap::Render(HDC hDC, float fDeltaTime)
{
	
	for (int x = 0; x < m_iWidth; x++) {
		for (int y = 0; y < m_iHeight; y++) {
			int dx = m_tPos.x + x * GetSize().x;
			int dy = m_tPos.y + y * GetSize().x;
			if (m_arrCell[x][y])
				BitBlt(hDC, dx, dy, dx + GetSize().x, dy + GetSize().x, m_pTexture->GetDC(), 0, 0, SRCCOPY);
			else
				Rectangle(hDC, dx, dy, dx + GetSize().x, dy + GetSize().x);
		}
	}
}

CMap* CMap::Clone()
{
	return new CMap(*this);
}
