#include "Input.h"

CInput::CInput() :
	m_pCreateKey(NULL)
{
}

CInput::~CInput()
{
	Safe_Delete_Map(m_mapKey);
}

bool CInput::Init(HWND hWnd)
{
	m_hWnd = hWnd;

	AddKey('A', "MoveLeft");
	AddKey('D', "MoveRight");


	return true;
}

void CInput::Update(float fDeltaTime)
{
	unordered_map<string, PKEYINFO>::iterator iter;
	unordered_map<string, PKEYINFO>::iterator iterEnd = m_mapKey.end();

	for (iter = m_mapKey.begin(); iter != iterEnd; ++iter) {

	}
}
