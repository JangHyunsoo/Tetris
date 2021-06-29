#include "BlockDataBase.h"

unordered_map<char, CBlockData*> CBlockDataBase::m_mapPrototype;

bool CBlockDataBase::Init()
{
	m_mapPrototype.insert(make_pair('O', new CBlockData('O', 1, { {-1, 0}, {0, 0}, {-1, -1}, {0, -1} })));
	m_mapPrototype.insert(make_pair('I', new CBlockData('I', 2, { {-2, 0}, {-1, 0}, {0, 0}, {1, 0} })));
	m_mapPrototype.insert(make_pair('S', new CBlockData('S', 2, { {0, 0}, {1, 0}, {-1, -1}, {0, -1} })));
	m_mapPrototype.insert(make_pair('Z', new CBlockData('Z', 2, { {-1, 0}, {0, 0}, {0, -1}, {1, -1} })));
	m_mapPrototype.insert(make_pair('L', new CBlockData('L', 4, { {-1, 0}, {0, 0}, {1, 0}, {-1, -1} })));
	m_mapPrototype.insert(make_pair('J', new CBlockData('J', 4, { {-1, 0}, {0, 0}, {1, 0}, {1, -1} })));
	m_mapPrototype.insert(make_pair('T', new CBlockData('T', 4, { {-1, 0}, {0, 0}, {1, 0}, {0, -1} })));
	return true;
}

CBlockData* CBlockDataBase::GetData(char cKey)
{
	unordered_map<char, CBlockData*>::iterator iter = m_mapPrototype.find(cKey);

	if (iter == m_mapPrototype.end())
		return NULL;

	return iter->second;
}