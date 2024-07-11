#include <stdio.h>

// 메모리 정렬을 1바이트 최소단위로 강제지정
//#pragma pack(1)


// 구조체 크기
// 가장 큰 맴버의 자료형을 기준으로 메모리 정렬
struct My
{
	int i;
	float s;
	char arr[5];
};

struct NewType
{
	float f[2];
};

int main()
{
	int size = sizeof(My);

	NewType type = {};

	return 0;
}