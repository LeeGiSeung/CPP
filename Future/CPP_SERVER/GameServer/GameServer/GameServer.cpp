#include "pch.h"
#include "CorePch.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>

using namespace std;

int64 result = 0;

int64 Calculate() {
	int64 sum = 0;

	for (int32 i = 0; i < 100000; i++) {
		sum += i;
	}
	result = sum;
	return sum;

}

void TaskWorker(std::packaged_task<int64>&& task) {
	task();
}

int main()
{
	//동기(synchronous) 방식 실행
	int64 sum = Calculate();
	cout << sum << endl;

	thread t(Calculate);
	t.join();



	//한번의 작업을 위해 Thread를 부여하는 것은 불필요 할 수도 있다.
	//그래서 사용하는 것이 std::future 비동기 방식으로 구현
	//옵션
	//std::launch
	//1)deferred -> lazy evaluation 지연해서 실행하세요
	//2)async -> 별도의 쓰레드를 만들어서 실행하세요 (사실항 Multi Thread상태)
	//3)deferred | async -> 둘 중 알아서 골라주세요
	{
		
		//언젠가 미래에 결과물을 뱉어줄 거야.
		std::future<int64> future = std::async(std::launch::async, Calculate);


		//내가 시킨일 끝남?
		std::future_status status = future.wait_for(1ms);

		//내가 시킨일 끝남?
		//결과물이 이제 필요하다.
		int64 sum = future.get();

	}

	//2번째 future 객체를 만드는 방법
	//std::promise
	{
		//미래(std::future)에 결과물을 반환해줄꺼라 약속(std::promise)해라
		std::promise<string> promise;
		std::future<string> future = promise.get_future();
	}

	// std::package_task
	{
		std::packaged_task<int64(void)> task(Calculate);
		std::future<int64> future = task.get_future();

		std:: thread;
	}

	//결론)
	//mutex, condition_variable까지 가지 않고 단순한 애들을 처리 할 수 있는
	//한번 호출해서 처리하는거면 굳이 condition_variable까지 갈 필요 없이 future로만 처리가능 단발성 이벤트에 유용하다.

	//1)async
	//원하는 함수를 비동기적으로 실행
	//2) promise
	//결과물을 promise를 통해 future로 받아줌
	//3)packaged_task
	//원하는 함수의 실행 결과를 packaged_task를 통해 받아줌

}
