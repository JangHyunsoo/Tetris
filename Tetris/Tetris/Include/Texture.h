#pragma once
#include "Ref.h"

class CTexture :
	public CRef
{
private:
	friend class CResourceManager;

private:
	CTexture();
	~CTexture();

private:
	HDC m_hMemDC;
	HBITMAP m_hBitmap;

public:
	bool LoadTexture(HINSTANCE hInst, HDC hDC, const string& strKey, const wchar_t* pFileName, const string& strPathKey = TEXTURE_PATH);;

};