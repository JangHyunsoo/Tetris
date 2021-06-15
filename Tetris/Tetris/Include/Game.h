#pragma once
#include <iostream>
#include <Windows.h>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

#include "resource.h"
#include "Mecro.h"
#include "Type.h"
#include "Flag.h"

template<typename T>
void Safe_Delete_VecList(T& p) {
	auto iterEnd = p.end();

	for (auto iter = p.begin(); iter != iterEnd; ++iter) {
		SAFE_DELETE((*iter));
	}

	p.clear();
}