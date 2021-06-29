#pragma once
#include "BlockData.h"

class CBlockDataBase
{
private:
	static unordered_map<char, CBlockData*> m_mapPrototype;
public:
	static bool Init();
	static CBlockData* GetData(char cKey);
};

