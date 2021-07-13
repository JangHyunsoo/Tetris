#pragma once
#include "StaticObj.h"
class CBlockQueue :
    public CStaticObj
{
private:
    vector<char> m_vecBlockType;
    vector<char> m_vecType;

public:
    CBlockQueue();
    CBlockQueue(const CBlockQueue& obj);
    ~CBlockQueue();

public:
    void FillQueue();
    char PopQueueBlock();

public:
    virtual bool Init();
    virtual void Render(HDC hDC, float fDeltaTime);
    virtual CBlockQueue* Clone();
};

