#pragma once
#include <mutex>

class Account {

};

class accountmanager
{
public:
	static accountmanager* Instance() {
		static accountmanager instance;
		return &instance;
	}

	Account* GetAccout(int32 id) {
		return nullptr
	}

};

