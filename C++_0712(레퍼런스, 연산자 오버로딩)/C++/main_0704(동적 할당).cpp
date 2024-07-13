#include <stdlib.h>

// 메모리 영역
// 1. 스택 (함수, 지역변수)
// 2. 데이터 ( 프로세스 시작 시, 프로세스 종료 시)
//   - 전역변수, 정적변수, 외부변수
// 3. ROM ( Relad Only Memory )
//   - 전역 변수 초기화 데이터, 문자열 데이터, 코드
// 4. 힙 (Heap)
//   - 동적할당으로 사용 가능

typedef int MYINT;

//#define MYINT int




int global[2000] = {};

int main()
{		
	int arr[100] = {};

	MYINT a = 0;

	// F12
	size_t size = 0;
	time_t time = 0;

	// 동적할당
	int* pData = (int*) malloc(20);

	pData[0] = 10; // *(pData + 0)
	pData[1] = 20; // *(pData + 1)
	pData[2] = 30; // *(pData + 2)
	pData[3] = 40; // *(pData + 3)
	pData[4] = 50; // *(pData + 4)

	// 할당하지 않은 공간까지 포인터를 이용해 접근해서 데이터를 기록(사용) 한 경우
	// Heap Corruption( 힙 손상 )
	pData[5] = 60; // *(pData + 4)
	pData[6] = 70; // *(pData + 4)

	// 1. 힙 메모리 영역에 할당하지 않은 곳까지 접근, 데이터를 사용
	// 2. 할당한 힙 영역에 대한 반환이 이루어지지 않음
	//   - 메모리 누수(Leak)

	free(pData);

	//int IArr[3] = {};
	//IArr[3] = 10;

	return 0;
}