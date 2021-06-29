#pragma once
#include "StaticObj.h"
#include "BlockData.h"

class CMap :
    public CStaticObj
{
private:
    CMap();
    ~CMap();
private:
    const int m_iHeight = 20;
    const int m_iWidth = 10;
    bool m_arrCell[20][10];
public:
    void SetCell(int x, int y) {
        m_arrCell[y][x] = true;
    }
    bool GetCell(int x, int y) {
        return m_arrCell[y][x];
    }
public:
    bool CheckMove(int x, int y, const CBlockData& tBlockData);
};

