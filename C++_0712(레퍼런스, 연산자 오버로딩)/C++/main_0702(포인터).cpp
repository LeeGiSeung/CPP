#include <iostream>

int Global = 0;


int* TestFunc()
{
	static int iStatic = 0; // 정적변수
						    // Data 영역 메모리 사용
	Global = 0;

	return &iStatic;
}


int main()
{	
	Global = 0;

	int i = 0;

	int* pStatic = TestFunc();
	*pStatic = 1000;

	TestFunc();

	// 포인터 변수
	// 1. 크기가 플랫폼 크기를 따라간다. x64 기준 8바이트, x86 기준 4바이트
	// 2. 정수 표현체계를 따름
	// 3. 주소를 저장하는 변수
	int* p = nullptr; // 주소값이 0 == null 포인터

	// 포인터변수 P 에 int 변수 i 의 주소값을 입력
	p = &i;

	// 포인터변수에 입력된 주소로 접근해서 그곳에 100을 넣는다 ==> i 변수에 100 이 들어간다.
	*p = 100;


	// 주소의 최소 단위는 1 바이트

	// 32 비트 = 4바이트
	// 2^32 가지수 42억 9천 7백만
	// 0 ~ (2^32 - 1)

	// 8 비트 , 256 가지
	// 0 ~ (2^8 - 1)





	return 0;
}