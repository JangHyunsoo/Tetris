#include "BlockQueue.h"
#include "BlockDataBase.h"
#include "ResourceManager.h"

CBlockQueue::CBlockQueue()
{
}

CBlockQueue::CBlockQueue(const CBlockQueue& obj) :
	CStaticObj(obj),
	m_vecType(obj.m_vecType)
{
}

CBlockQueue::~CBlockQueue()
{
}

void CBlockQueue::FillQueue() {
	random_device rd;
	mt19937 g(rd());
	shuffle(m_vecType.begin(), m_vecType.end(), g);

	for (auto cType : m_vecType) {
		m_vecBlockType.push_back(cType);
	}
}

char CBlockQueue::PopQueueBlock() {
	if (m_vecBlockType.size() <= 4) {
		FillQueue();
	}
	char cType = m_vecBlockType[m_vecBlockType.size() - 1];
	m_vecBlockType.pop_back();
	return cType;
}

bool CBlockQueue::Init()
{
	m_vecType = { 'O','I','S','Z','L','J','T' };
	FillQueue();
	return true;
}

void CBlockQueue::Render(HDC hDC, float fDeltaTime)
{
	Rectangle(hDC, m_tPos.x, m_tPos.y, m_tPos.x + m_tSize.x * 4 + 20, m_tPos.y + m_tSize.y * 13 + 20);

	if (!m_vecBlockType.empty()) {

		for (int t = 0; t < 3; t++) {
			vector<POSITION> arrData = CBlockDataBase::GetData(m_vecBlockType[m_vecBlockType.size() - t - 1])->GetData(0);

			for (int i = 0; i < arrData.size(); i++) {
				int x = m_tPos.x + ((arrData[i].x + 2) * m_tSize.x) + 10;
				int y = m_tPos.y + ((arrData[i].y + 2) * m_tSize.y) + 10 + t * 150;
				BitBlt(hDC, x, y, m_tSize.x, m_tSize.y, CResourceManager::GetInst()->FindTexture(CBlockDataBase::GetData(m_vecBlockType[m_vecBlockType.size() - t - 1])->GetTexture())->GetDC(), 0, 0, SRCCOPY);
			}
		}
	}
}

CBlockQueue* CBlockQueue::Clone()
{
	return new CBlockQueue(*this);
}

