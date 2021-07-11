#pragma once
#include "StaticObj.h"
class CMap :
    public CStaticObj
{
public:
    CMap();
    CMap(const CMap& obj);
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
    bool CheckLine(int y);
    void BreakLine(int y);

private:
    bool IsMap(int x, int y); 

public:
    virtual bool Init();
    virtual void Render(HDC hDC, float fDeltaTime);
    virtual CMap* Clone();
};