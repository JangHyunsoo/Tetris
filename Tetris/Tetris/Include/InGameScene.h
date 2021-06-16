#pragma once
#include "Scene.h"
class CInGameScene :
    public CScene
{
private:
    friend class CSceneManager;
private:
    CInGameScene();
    ~CInGameScene();
public:
    virtual bool Init();
    virtual void Input(float fDeltaTime);
    virtual int Update(float fDeltaTime);
    virtual int LateUpdate(float fDeltaTime);
    virtual void Collision(float fDeltaTime);
    virtual void Render(HDC hDC, float fDeltaTime); 
};

