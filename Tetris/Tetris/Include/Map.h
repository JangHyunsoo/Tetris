#pragma once
#include "StaticObj.h"
class CMap :
    public CStaticObj
{
private:
    CMap();
    ~CMap();
private:
    const int m_iHeight = 20;
    const int m_iWidth = 10;
    bool m_arrCell[10][20];
public:
    void SetCell(int x, int y, bool bValue); 
    bool GetCell(int x, int y); 
public:
    void SetBlock(int x, int y, char cBlockType, int iRot);
    bool CheckMove(int x, int y, char cBlockType, int iRot);
    void BreakLine(int y);

private:
    bool IsMap(int x, int y); 
    bool CheckLine(int y);

public:
    bool Init();
    void Render(HDC hDC, float fDeltaTime);

};