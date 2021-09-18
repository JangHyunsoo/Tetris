#pragma once
#include "Game.h"

class CBlockData
{
public:
	CBlockData();
	CBlockData(char cType);
	CBlockData(char cType, string strTexture ,int iSize, vector<POSITION> arrData);
	~CBlockData();
private:
	char m_cType;
	string m_strTexture;
	int m_iSize;
	vector<POSITION> m_arrData;
public:
	const string& GetTexture() {
		return m_strTexture;
	}

	vector<POSITION> GetData(int rot) {
		vector<POSITION> arrResult;
		
		for (int i = 0; i < m_arrData.size(); i++)
		{
			switch (rot % m_iSize)
			{
			case 0:
				arrResult.emplace_back(m_arrData[i].x, m_arrData[i].y);
				break;
			case 1:
				arrResult.emplace_back(m_arrData[i].y * -1, m_arrData[i].x);
				break;
			case 2:
				arrResult.emplace_back(m_arrData[i].x * -1, m_arrData[i].y * -1);
				break;
			case 3:
				arrResult.emplace_back(m_arrData[i].y, m_arrData[i].x * -1);
				break; 
			default:
				arrResult.emplace_back(m_arrData[i].x, m_arrData[i].y);
				break;
			}
		}

		return arrResult;
	}
};