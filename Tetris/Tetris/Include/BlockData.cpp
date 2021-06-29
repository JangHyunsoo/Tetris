#include "BlockData.h"

CBlockData::CBlockData() :
	m_cType(NULL)
{
}

CBlockData::CBlockData(char cType) :
	m_cType(cType)
{
}

CBlockData::CBlockData(char cType, vector<POSITION> arrData, int iSize) :
	m_cType(cType),
	m_arrData(arrData),
	m_iSize(iSize)
{
}

CBlockData::CBlockData(char cType, int iSize, vector<POSITION> arrData) :
	m_cType(cType),
	m_arrData(arrData),
	m_iSize(iSize)
{
}

CBlockData::~CBlockData()
{
}
