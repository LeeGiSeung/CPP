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

void Producer() {
	while (true) {
		unique_lock<mutex>  lock(m);
		q.push(100);
	}

	//Signal 상태로 변환
	::SetEvent(handle);
	//0.1초
	this_thread::sleep_for(100ms);
}

//Producer의 시간이 늘어날 수록 Consumer는 wait하는 시간이 늘어나면서 불필요한 CPU사용량이 증가하게 됨
void Consumer() {
	while (true) {
		//handle 오브젝트를 영원히 기다려라
		//무한 뺑뺑이를 돌던 것이 Producer의 시그널을 기달릴때까지 무한 대기
		::WaitForSingleObject(handle, INFINITE);
		//자동으로 Non-Signal로 변경
		//::ResetEvent(handle);
		//만약 자동 변경을 True로 해놨을시 수동으로 변경해야함
		unique_lock<mutex> lock(m);

		if (q.empty() == false) {
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
