#include "pch.h"
#include "CorePch.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>

mutex m;
queue<int32> q;
HANDLE handle;

//CV는 User-level Object(커널 오브젝트x)
//커널오브젝트는 다른 프로그램끼리도 동기화가 가능하지만 유저 오브젝트는 프로그램 내부에서만 가능하다.
condition_variable cv;

//#include <condition_variable>
//condition_variable_any cv;

void Producer() {

	while (true) {
		unique_lock<mutex>  lock(m);
		q.push(100);
	}

	//Signal 상태로 변환
	::cv.notify_one();
	//0.1초
	this_thread::sleep_for(100ms);
}

//Producer의 시간이 늘어날 수록 Consumer는 wait하는 시간이 늘어나면서 불필요한 CPU사용량이 증가하게 됨
void Consumer() {

	while (true) {
		unique_lock<mutex> lock(m);
		//wait사용할때는 "조건"이 필요하기 때문에 무조건 uniqueLock을 사용해야 한다.

		//notify_one 했으면 조건 안보고 그냥 깨워도 되는거 아니냐?
		//중간에 누가 가로챌 수 있기 때문에 조건을 걸어서 다시 확인해주어야한다.(Spurious Wakeup 가짜 기상 상태 발생 가능성있음)
		cv.wait(lock, []() { return q.empty() == false; });
		
		
		//lock을 잡을려고 시도
		//조건 확인
		//만족 -> 빠져나와서 이어서 코드 진행(wait을 실행하지않음)
		//불만족 -> lock을 풀어주고 대기상태로 전환


		
		{
			int32 data = q.front();
			q.pop();
			cout << data << endl;
		}
	}
}

int main()
{
	//커널 오브젝트
	//커널에서 관리하고 있는 객체
	//나중에 여러 프로그램에서의 동기화 작업할때 커널 오브젝트를 사용하면 프로세스들 끼리 동기화 가능
	// 기존 만들었던 spin_lock은 유저 단에서 가능하지만 커널은 system 단에서 가능
	//Usage Count
	//Signal(파란불), Non_Signal (빨간불) << bool
	//Auto/Manual << bool


	//CreateEvent : windows.h
	//Handle 많은 Event중에 구별하는 식별자
	//bManualReset를 False로 설정해주었기 때문에 자동으로 Non-signal로 바뀜
	HANDLE handle = ::CreateEvent(NULL, FALSE, FALSE, NULL);

	thread t1(Producer);
	thread t2(Consumer);

	t1.join();
	t2.join();

	::CloseHandle(handle);
}
