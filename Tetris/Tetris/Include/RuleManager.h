#pragma once
#include "BlockData.h"

class CRuleManager
{
    DECLARE_SINGLE(CRuleManager)

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
    void SetCell(int x, int y, char cBlockType, int iRot);
    bool CheckMove(int x, int y, char cBlockType, int iRot);

private:
    bool IsMap(int x, int y) {
        return x < m_iWidth&& y < m_iHeight&& x >= 0 && y >= 0;
    }

public:
    bool Init();
    void Render(HDC hDC, float fDeltaTime);
};

