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
		lock_guard<mutex> guard(m);


		return nullptr;
	}

	void ProcessLogin();

private:
	mutex m;
};

