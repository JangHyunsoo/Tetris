#pragma once
#include "StaticObj.h"

class CHold :
    public CStaticObj
{
public:
    CHold();
    CHold(const CHold& obj);
    ~CHold();
private:
    char m_cType;
    bool m_bChange;

public:
    void SetType(char cType) {
        m_cType = cType;
    }
    void SetChange(bool bChange) {
        m_bChange = bChange;
    }

    char GetType() {
        return m_cType;
    }
    bool CanChange() {
        return m_bChange;
    }

public:
    char ChangeType(char cType);
    

public:
    virtual bool Init();
    virtual void Input(float fDeltaTime);
    virtual void Render(HDC hDC, float fDeltaTime);
    virtual CHold* Clone();
};

