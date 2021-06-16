#include "Core.h"
#include "SceneManager.h"
#include "Timer.h"

DEFINITION_SINGLE(CCore)
bool CCore::m_bLoop = true;

CCore::CCore()
{
}

CCore::~CCore()
{
	DESTROY_SINGE(CTimer)
	DESTROY_SINGE(CSceneManager)
	DESTROY_SINGE(CCore)
}

bool CCore::Init(HINSTANCE hInst)
{
	this->m_hInst = hInst;

	MyRegisterClass();

	m_tRS.iW = 1280;
	m_tRS.iH = 720;

	Create();

	m_hDC = GetDC(m_hWnd);

	if (!GET_SINGE(CTimer)->Init())
		return false;

	if (!GET_SINGE(CSceneManager)->Init())
		return false;

	return true;
}

BOOL CCore::Create()
{
	m_hWnd = CreateWindowW(L"hello world", L"hello world", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_hInst, nullptr);

	if (!m_hWnd) {
		return FALSE;
	}

	RECT rc = { 0, 0, m_tRS.iW, m_tRS.iH };


	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	SetWindowPos(m_hWnd, HWND_TOPMOST, 100, 100, rc.right - rc.left, rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER);

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return 0;
}


int CCore::Run()
{
	MSG msg;

	while (m_bLoop)
	{

		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			Logic();
		}
	}

	// ReleaseDC(m_hWnd, m_hDc);

	return (int)msg.wParam;
}

void CCore::Logic()
{
	GET_SINGE(CTimer)->Update();

	float fDeltaTime = GET_SINGE(CTimer)->GetDeltaTime();

	Input(fDeltaTime);
	Update(fDeltaTime);
	LateUpdate(fDeltaTime);
	Collision(fDeltaTime);
	Render(fDeltaTime);

}

void CCore::Input(float fDeltaTime)
{
	GET_SINGE(CSceneManager)->Input(fDeltaTime);
}

int CCore::Update(float fDeltaTime)
{
	GET_SINGE(CSceneManager)->Update(fDeltaTime);
	return 0;
}

int CCore::LateUpdate(float fDeltaTime)
{
	GET_SINGE(CSceneManager)->LateUpdate(fDeltaTime);
	return 0;
}

void CCore::Collision(float fDeltaTime)
{
	GET_SINGE(CSceneManager)->Collision(fDeltaTime);
}

void CCore::Render(float fDeltaTime)
{
	GET_SINGE(CSceneManager)->Render(m_hDC,fDeltaTime);
}

LRESULT CCore::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY: {
		m_bLoop = false;
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}


ATOM CCore::MyRegisterClass() {
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW || CS_VREDRAW;
	wcex.lpfnWndProc = CCore::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInst;
	wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"hello world";
	wcex.hIconSm = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassExW(&wcex);
}