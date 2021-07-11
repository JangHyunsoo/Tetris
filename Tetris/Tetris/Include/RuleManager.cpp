#include "RuleManager.h"
#include "BlockDataBase.h"

DEFINITION_SINGLE(CRuleManager);

CRuleManager::CRuleManager() :
	m_vecType({'O','I','S','Z','L','J','T'})
{
}

CRuleManager::~CRuleManager()
{
}

bool CRuleManager::Init() {

	return true;
}

void CRuleManager::StartGame(POSITION tZero, float fBlockSize, CLayer* pLayer)
{
	m_tZero = tZero;
	m_fBlockSize = fBlockSize;

	random_device rd;
	mt19937 g(rd());
	shuffle(m_vecType.begin(), m_vecType.end(), g);

	for (auto cType : m_vecType) {
		m_qBlockType.push(cType);
	}

	CreateMap(pLayer);
	CreateBlock(pLayer);
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

	m_pBlock->SetType(m_qBlockType.front()); m_qBlockType.pop();
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

void CRuleManager::FillQueue() {
	random_device rd;
	mt19937 g(rd());
	shuffle(m_vecType.begin(), m_vecType.end(), g);

	for (auto cType : m_vecType) {
		m_qBlockType.push(cType);
	}
}

char CRuleManager::GetQueueBlock() {
	if (m_qBlockType.size() <= 4) {
		FillQueue();
	}
	char cType = m_qBlockType.front();
	m_qBlockType.pop();
	return cType;
}

void CRuleManager::MakeOriginBlock(char cType)
{
	m_pBlock->MakeOrigin(cType);
}
