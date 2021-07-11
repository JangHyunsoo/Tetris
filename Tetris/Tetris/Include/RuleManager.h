#pragma once
#include "BlockData.h"
#include "CursorBlock.h"
#include "Map.h"
#include "Hold.h"

class CRuleManager
{
    DECLARE_SINGLE(CRuleManager)

private:
    POSITION m_tZero;
    float m_fBlockSize;
    queue<char> m_qBlockType;
    vector<char> m_vecType;

private:
    // obj
    CMap* m_pMap;
    CCursorBlock* m_pBlock;
    // ui
    CHold* m_pHold;

public:
    CCursorBlock* GetBlock() {
        return m_pBlock;
    }

    float GetBlockSize() {
        return m_fBlockSize;
    }

    POSITION GetZero() {
        return m_tZero;
    }

public:
    POSITION ToGamePos(POSITION tWorldPos) {
        return POSITION((tWorldPos.x - m_tZero.x) / m_fBlockSize, (tWorldPos.y - m_tZero.y) / m_fBlockSize);
    }
    POSITION ToWorldPos(POSITION tGamePos) {
        return POSITION(tGamePos.x * m_fBlockSize + m_tZero.x, tGamePos.y * m_fBlockSize + m_tZero.y);
    }

public:
    bool Init();
    void StartGame(POSITION tZero, float iBlockSize, class CLayer* pLayer);
    void CreateHold(POSITION tPos, class CLayer* pLayer);
    void CreateBlock(class CLayer* pLayer);
    void CreateMap(class CLayer* pLayer);
    bool CheckMove(int x, int y, char cBlockType, int iRot);
    void SetBlock(int x, int y, char cBlockType, int iRot);
    void FillQueue();
    char GetQueueBlock();
    void MakeOriginBlock(char cType);
};
