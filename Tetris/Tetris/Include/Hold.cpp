#include "Hold.h"
#include "Input.h"
#include "RuleManager.h"
#include "Texture.h"
#include "BlockDataBase.h"
#include "ResourceManager.h"

CHold::CHold()
{
}

CHold::CHold(const CHold& obj) :
    CStaticObj(obj),
    m_cType(obj.m_cType)
{
}

CHold::~CHold()
{
}

char CHold::ChangeType(char cType)
{
    char cTemp = m_cType;
    m_cType = cType;
    return cTemp;
}

bool CHold::Init()
{
    m_cType = ' ';
    SetTexture("Yellow", L"Yellow.bmp");
    return true;
}

void CHold::Input(float fDeltaTime) {
    if (GET_SINGE(CInput)->KeyDown("Hold") && m_bChange) {
        if (m_cType != ' ') {
            GET_SINGE(CRuleManager)->MakeOriginBlock(ChangeType(GET_SINGE(CRuleManager)->GetBlock()->GetType()));
        }
        else {
            ChangeType(GET_SINGE(CRuleManager)->GetBlock()->GetType());
            GET_SINGE(CRuleManager)->MakeOriginBlock(GET_SINGE(CRuleManager)->GetBlockQueue()->PopQueueBlock());
        }
        m_bChange = false;
    }
}

void CHold::Render(HDC hDC, float fDeltaTime)
{
   Rectangle(hDC, m_tPos.x, m_tPos.y, m_tPos.x + m_tSize.x * 4 + 20, m_tPos.y + m_tSize.y * 4 + 20);

   if (m_cType != ' ') {
        vector<POSITION> arrData = CBlockDataBase::GetData(m_cType)->GetData(0);

        for (int i = 0; i < arrData.size(); i++) {
            int x = m_tPos.x + ((arrData[i].x + 2) * m_tSize.x) + 10;
            int y = m_tPos.y + ((arrData[i].y + 2) * m_tSize.y) + 10;
            BitBlt(hDC, x, y, m_tSize.x, m_tSize.y, CResourceManager::GetInst()->FindTexture(CBlockDataBase::GetData(m_cType)->GetTexture())->GetDC(), 0, 0, SRCCOPY);
        }
    }
}

CHold* CHold::Clone()
{
    return new CHold(*this);
}
