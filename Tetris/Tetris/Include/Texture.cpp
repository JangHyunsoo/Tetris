#include "Texture.h"

CTexture::CTexture() : 
	m_hMemDC(NULL)
{
}

CTexture::~CTexture()
{
}

bool CTexture::LoadTexture(HINSTANCE hInst, HDC hDC, const string& strKey, const wchar_t* pFileName, const string& strPathKey)
{
	// make mem DC
	m_hMemDC = CreateCompatibleDC(hDC);



	return true;
}