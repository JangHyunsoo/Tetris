#include "Scene.h"
#include "Layer.h"

CScene::CScene()
{
	CLayer* pLayer = CreateLayer("Default", 0);
	pLayer = CreateLayer("UI", INT_MAX);
}

CScene::~CScene()
{
	Safe_Delete_VecList(m_LayerList);
}

CLayer* CScene::CreateLayer(const string& strTag, int iZOrder)
{
	CLayer* pLayer = new CLayer;

	pLayer->SetTag(strTag);
	pLayer->SetZOrder(iZOrder);
	pLayer->SetScene(this);

	m_LayerList.push_back(pLayer);

	if (m_LayerList.size() >= 2) {
		m_LayerList.sort(CScene::LayerSort);
	}


	return pLayer;
}

bool CScene::Init()
{
	return true;
}

void CScene::Input(float fDeltaTime)
{
	auto iterEnd = m_LayerList.end();

	for (auto iter = m_LayerList.begin(); iter != iterEnd; ++iter) {
		(*iter)->Input(fDeltaTime);
	}
}

int CScene::Update(float fDeltaTime)
{
	auto iterEnd = m_LayerList.end();

	for (auto iter = m_LayerList.begin(); iter != iterEnd; ++iter) {
		(*iter)->Update(fDeltaTime);
	}
	return 0;
}

int CScene::LateUpdate(float fDeltaTime)
{
	auto iterEnd = m_LayerList.end();

	for (auto iter = m_LayerList.begin(); iter != iterEnd; ++iter) {
		(*iter)->LateUpdate(fDeltaTime);
	}
	return 0;
}

void CScene::Collision(float fDeltaTime)
{
	auto iterEnd = m_LayerList.end();

	for (auto iter = m_LayerList.begin(); iter != iterEnd; ++iter) {
		(*iter)->Collision(fDeltaTime);
	}
}

void CScene::Render(HDC hDC, float fDeltaTime)
{
	auto iterEnd = m_LayerList.end();

	for (auto iter = m_LayerList.begin(); iter != iterEnd; ++iter) {
		(*iter)->Render(hDC, fDeltaTime);
	}
}

bool CScene::LayerSort(CLayer* A, CLayer* B)
{
	return A->GetZOrder() < B->GetZOrder();
}
