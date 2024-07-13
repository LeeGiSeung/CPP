#include <stdio.h>

// 배열

// 구조체
struct MyDataType
{
	// 맴버
	int		i;
	float	f;
	short   sArr[5];
};


struct MyBigData
{
	MyDataType  Data[20];
	int			Size;
};

int main()
{
	// 배열(Array)
	int i0 = 0, i1 = 0, i2 = 0;

	// 배열의 선언방법, 초기화 방법
	int iArr[10] = {  };
	
	// 배열이름[인덱스];
	iArr[0];
	iArr[1];
	iArr[9] = 100;

	// 각 변수의 이름을 일일히 지어줄 필요가 없다.
	// 배열은 메모리가 연속적인 구조를 가진다.


	// 구조체(Struct)
	// 사용자가 만드는 자료형(User Define DataType)
	MyDataType data = {};
	data.i = 20;
	data.f = 3.14f;

	MyDataType data1;
	MyDataType data2;

	// 배열과 구조체
	MyDataType arrData[10] = {};
	arrData[0].i = 1;
	arrData[0].f = 1.f;

	arrData[9].i = 10;
	arrData[9].f = 10.f;

	arrData[4].sArr[4] = 20;

	int size = sizeof(MyDataType);


	// 구조체 크기


	return 0;
}