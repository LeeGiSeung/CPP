#include "pch.h"
#include "CorePch.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include <utility>

atomic<bool> ready;
int32 value;

void Producer() {
	value = 10;
	ready.store(true, memory_order::memory_order_seq_cst);
}

void Consumer() {
	while (ready.load(memory_order::memory_order_seq_cst) == false) {
	}

	cout << value << endl;
}

int main(){
	atomic<bool> flag;
	flag.store(false);

	// 이전 flag 값을 prev에 넣고, flag 값을 수정
	bool pre = flag.exchange(true);

	{
		bool excepted = false;
		bool desired = true;
		flag.compare_exchange_strong(excepted, desired);

		//compare_exchage_strong 슈도코드
		if (flag == excepted) {
			flag = desired;
			return true;
		}
		else {
			excepted = flag;
			return false;
		}

		//compare_exchage_strong과 week의 차이
		//동작 방식은 똑같지만 week는 다른 쓰레드의 간섭을 받아서 실패가 나올 수 있음
		//strong은 확실하지만 부하가 더 일어남
	}
	ready = false;
	value = 0;
	thread t1(Producer);
	thread t2(Consumer);

	t1.join();
	t2.join();

	//Momory Model(정책)
	//1) Sequentially Consistent (seq_cst)
	//2) Acquire-Release (acquire, release)
	//3) Relaxed (relaxed)

	//엄격한순( 컴파일러 최적화 여지가 적다 = 직관적 좋은거임)
	//1)Sequentially
	//2)Acquire-Release(release 이전 코드들이 release를 넘겨 재배치 되는 것을 방지 자기 전 코드들의 순서는 상관안함)
	//3)Relaxed(가시성, 코드 재배치)

	return;
}
