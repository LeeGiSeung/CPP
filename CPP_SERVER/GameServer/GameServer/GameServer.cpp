#include "pch.h"
#include "CorePch.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include "accountmanager.h"
#include "Usermanager.h"

void Func1() {
	for (int32 i = 0; i < 1000; i++) {
		Usermanager::Instance()->ProcessSave();
	}
}

void Func2() {
	for (int32 i = 0; i < 1000; i++) {
		accountmanager::Instance()->ProcessLogin();
	}
}

//DeadLock이 발생하면 MultiThread가 작동을 멈추는 현상을 볼 수 있음

int main()
{
	std::thread t1(Func1);
	std::thread t2(Func2);

	t1.join();
	t2.join();

	cout << "Jobs Done" << endl;

	return;
}
