#pragma once
#include <mutex>

class User {

};

class Usermanager
{
public:
	static Usermanager* Instance() {
		static Usermanager instance;
		return &instance;
	}

	User* GetUser(int32 id) {
		lock_guard<mutex> guard(m);
		return nullptr;
	}

	void ProcessSave();

private:
	mutex m;

};

