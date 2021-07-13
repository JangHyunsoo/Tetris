#include "RuleManager.h"
#include "BlockDataBase.h"

DEFINITION_SINGLE(CRuleManager);

CRuleManager::CRuleManager()
{
}

CRuleManager::~CRuleManager()
{
}

bool CRuleManager::Init() {

	return true;
}

void CRuleManager::SetBlockSize(float fBlockSize)
{
	m_fBlockSize = fBlockSize;
}


void CRuleManager::StartGame(POSITION tZero, CLayer* pLayer)
{
	m_tZero = tZero;

	CreateMap(pLayer);
	CreateBlock(pLayer);
}

void CRuleManager::CreateQueue(POSITION tPos, CLayer* pLayer)
{
	CObj::CreatePrototype<CBlockQueue>("BlockQueue");

	m_pBlockQueue = static_cast<CBlockQueue*>(CObj::CreateCloneObj("BlockQueue", "blockqueue", pLayer));
	m_pBlockQueue->SetSize(m_fBlockSize, m_fBlockSize);
	m_pBlockQueue->SetPos(tPos);
	m_pBlockQueue->FillQueue();
}

void CRuleManager::CreateHold(POSITION tPos, CLayer* pLayer)
{
	CObj::CreatePrototype<CHold>("Hold");

	m_pHold = static_cast<CHold*>(CObj::CreateCloneObj("Hold", "hold", pLayer));
	m_pHold->SetSize(m_fBlockSize, m_fBlockSize);
	m_pHold->SetPos(tPos);
}

void CRuleManager::CreateBlock(CLayer* pLayer)
{
	CObj::CreatePrototype<CCursorBlock>("CursorBlock");

	m_pBlock = static_cast<CCursorBlock*>(CObj::CreateCloneObj("CursorBlock", "block", pLayer));

	m_pBlock->SetType(m_pBlockQueue->PopQueueBlock());
	m_pBlock->SetSize(m_fBlockSize, m_fBlockSize);
	m_pBlock->SetGamePos(POSITION(5, 1));
	m_pBlock->SetPos(ToWorldPos(m_pBlock->GetGamePos()));
}

void CRuleManager::CreateMap(CLayer* pLayer)
{
	CObj::CreatePrototype<CMap>("Map");

	m_pMap = static_cast<CMap*>(CObj::CreateCloneObj("Map", "map", pLayer));

	m_pMap->SetSize(m_fBlockSize, m_fBlockSize);
	m_pMap->SetPos(m_tZero);
}

bool CRuleManager::CheckMove(int x, int y, char cBlockType, int iRot)
{
	return m_pMap->CheckMove(x, y, cBlockType, iRot);
}

void CRuleManager::SetBlock(int x, int y, char cBlockType, int iRot)
{
	m_pMap->SetBlock(x, y, cBlockType, iRot);

	for(int i = y - 2; i <= y + 2; i++){
		if (m_pMap->CheckLine(i)) m_pMap->BreakLine(i);
	}

	m_pHold->SetChange(true);
}

void CRuleManager::MakeOriginBlock(char cType)
{
	m_pBlock->MakeOrigin(cType);
}

void CRuleManager::GameOver()
{
	// do something
}
