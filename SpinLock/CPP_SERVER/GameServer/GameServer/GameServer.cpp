#include "pch.h"
#include "CorePch.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

class SpinLock {
public:
	void lock() {

		bool expected = false;
		bool desired = true;
		
		//CAS 의사코드
		// _locked와 expected가 같을 시 excepted에 _locked를 넣고 _locked에 desired를 넣음 return true
		// else excepted = _locked; return false;

		//CPU를 낭비하는 행동이 되기도 한다.
		while (_locked.compare_exchange_strong(expected, desired)) {
			bool expected = false;
		}

	}

	void unlock() {
		//store 과 load 는 atomic 객체들에 대해서 원자적으로 쓰기와 읽기를 지원해주는 함수 입니다.
		_locked.store(false);
	}

private:
	//volatile 최적화를 하지마라 몇 가지 케이스 외에는 사용안함
	//무슨 의미이냐?
	//귀찮겠지만 무시하지마라
	//volatile 대신에 atomic 사용 atomic이 volatile기능 포함한거임
	atomic<bool> _locked = false;
};

int32 sum = 0;
mutex m;

void Add() {
	for (int32 i = 0; i < 100000; i++) {
		lock_guard<mutex> guard(m);
		sum++;
	}
}

void Sub() {
	for (int32 i = 0; i < 100000; i++) {
		lock_guard<mutex> guard(m);
		sum--;
	}
}

int main()
{
	//mutex를 이용하면 쉽지만 오늘은 직접 lock을 구현 해 볼 것이다.
	thread t1(Add);
	thread t2(Sub);

	t1.join();
	t2.join();

	cout << sum << endl;

	return;
}
