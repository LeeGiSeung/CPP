#include <stdio.h>

// 변수의 종료
// 1. 지역변수			- 스택
// 2. 전역변수			- 데이터
// 3. 정적변수(static)	- 데이터
// 4. 외부변수(extern)	- 데이터


// 하나의 파일에서 코드를 늘려나가는 경우
// 단점
// 1. 유지보수가 어렵다
// 2. 협업이 불편함
// 3. 하나의 CPP 가 컴파일 될수있는 한계가 존재함

// 장점
// 1. 컴파일속도가 빠르다


// 코드를 분할해서 구현하는 경우
// 1. 유지보수가 쉬워진다. (파일 단위로 관련있는 기능들을 모아둠)
// 2. 협업이 용이함
// 3. 파일단위로 코드를 분할해서 컴파일에 문제점이 없어짐

// 단점
// 1. 컴파일 속도가 느려진다.


// 전방선언
#include "MyMath.h"

// 전역변수 (Global)
// 프로그램 시작 -> 프로그램 종료시 까지 존재하는 변수
// 데이터 영역에 저정됨
// 함수의 호출 종료에 상관없이 계속 유지되는 변수
// 어느 함수에서든 접근이 가능 (장점, 단점)
int g_int = 0;
static int g_Static = 0;
extern int RealGlobalValue;

// 정적변수(Static)
// 1. 데이터 영역에 변수가 저장됨
// 2. 정적 변수가 선언된 함수가 최초 호출될 때 초기화 됨 (한번만 진행)
// 3. 정적변수를 선언한 함수에서만 접근 가능

void Test()
{
	++g_int;

	// 정적 변수 (static)
	// Test 함수 전용 전역변수
	static int TestCallCount = 0;
	++TestCallCount;
}


int main()
{
	// 지역변수 (Local)
	// 변수가 선언된 함수가 호출될 때 생성
	// 스택 영역
	int Value = Pow(2, 4);


	Test();
	Test();
	Test();

	g_int = 1000;
	g_Static = 100;
	//TestCallCount = 10;
	RealGlobalValue = 0;

	Test();
	Test();
	Test();

	return 0;
}


int RealGlobalValue = 0;