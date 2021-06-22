#pragma once
#include "Game.h"

typedef struct _tagKeyInfo {
	string strName;
	vector<DWORD> vecKey;
	bool bDown;
	bool bPress;
	bool bUp;
	_tagKeyInfo() :
		bDown(false),
		bPress(false),
		bUp(false) {}
}KEYINFO, *PKEYINFO;

class CInput{
private:
	HWND m_hWnd;
	unordered_map<string, PKEYINFO> m_mapKey;
	PKEYINFO* m_pCreateKey;

public:
	bool Init(HWND hWnd);
	void Update(float fDeltaTime);

public:
	template <typename T>
	bool AddKey(const T& data) {
		return true;
	}

	template <typename T, typename... Types>
	bool AddKey(const T& data,const Types& ... args) {
		if (!m_pCreateKey) {
			m_pCreateKey = new PKEYINFO;
		}

		const char* pType = typeid(T).name();

		if(strcmp(pType, "char") == 0 ||
			strcmp(pType, "int" == 0)) {
			m_pCreateKey->vecKey.push_back((DWORD)data);
		}
		else {
			m_pCreateKey->strName = data;
				m_mapKey.insert(make_pair(m_pCreateKey->strName, m_pCreateKey));
		}

		AddKey(args...);

		if (m_pCreateKey)
			m_pCreateKey = NULL;

		return true;
	}

	DECLARE_SINGLE(CInput)
};

void Test() {
	unique_ptr<int> num(new int(5));

}