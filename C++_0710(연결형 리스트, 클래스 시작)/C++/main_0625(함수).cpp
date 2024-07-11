#include <stdio.h>

// 함수
// 메모리 영역
// 스택 메모리

// 스택이란?
// 자료구조

// 자료 구조(Data Structure)
// Data 를 관리

// 스택 - 선입 후출( 후입 선출 )
// 접시 쌓기

// 큐 - 선입 선출, (후입 후출)
// 줄서기



// 반환타입, 함수 이름, 함수 인자
void TestFunction()
{
	printf("안녕하세요");
}

// 전방선언
int Add(int, int);

int main()
{
	int k = 200;

	int i = Add(200, 9797);

	for (int i = 0; i < 10; ++i)
	{
		printf("*");
	}

	TestFunction();

	int a = Add(100, 100);

	return 0;
}

int Add(int _a, int _b)
{
	int c = _a + _b;

	return c;
}


// F9 : 중단점 생성 및 제거
// F5 : 디버깅 모드로 프로그램 시작
//      다음 중단점 까지 실행

// F10 : 프로시저 단위로 실행, 현재 중단걸린 지점에서 한줄 진행
// F11 : 한단계 실행, 동작의 최소단위 실행