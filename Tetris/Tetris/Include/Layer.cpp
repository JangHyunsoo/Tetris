#include "Layer.h"

CLayer::CLayer() : 
	m_iZOrder(0),
	m_strTag(""),
	m_pScene(NULL)
{
}

CLayer::~CLayer()
{
	Safe_Release_VecList(m_ObjList);
}

void CLayer::Input(float fDeltaTime)
{
	auto iterEnd = m_ObjList.end();

	for (auto iter = m_ObjList.begin(); iter != iterEnd; ++iter) {
		(*iter)->Input(fDeltaTime);
	}
}

int CLayer::Update(float fDeltaTime)
{
	auto iterEnd = m_ObjList.end();

	for (auto iter = m_ObjList.begin(); iter != iterEnd; ++iter) {
		(*iter)->Update(fDeltaTime);
	}
	return 0;
}

int CLayer::LateUpdate(float fDeltaTime)
{
	auto iterEnd = m_ObjList.end();

	for (auto iter = m_ObjList.begin(); iter != iterEnd; ++iter) {
		(*iter)->LateUpdate(fDeltaTime);
	}
	return 0;
}

void CLayer::Collision(float fDeltaTime)
{
	auto iterEnd = m_ObjList.end();

	for (auto iter = m_ObjList.begin(); iter != iterEnd; ++iter) {
		(*iter)->Collision(fDeltaTime);
	}
}

void CLayer::Render(HDC hDC, float fDeltaTime)
{
	auto iterEnd = m_ObjList.end();

	for (auto iter = m_ObjList.begin(); iter != iterEnd; ++iter) {
		(*iter)->Render(hDC, fDeltaTime);
	}
}
