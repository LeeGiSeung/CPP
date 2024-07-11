#include <iostream>

typedef struct MyType 
{ 
	int		a; 
	float	f;  
}  NewType;

typedef struct _tagDataType
{
	char c;
	short s;
	int i;
} DataType;


void Test(int* _pInt)
{
	*_pInt = 100;
}

//int global = 10;
//int global_arr[global];



int main()
{
	int integer = 0;
	Test(&integer);




	DataType		type;
	_tagDataType	type1;

	// 자료형
	// 정수타입
	//  - signed(음수, 양수)
	//  - unsigned(양수)
	
	// 실수타입
	// - float
	// - double
	float f = 0.f;
	double d = 1.11;
	f = (float)d;

	// 연산자
	// ++, --
	int b = 0;
	int a = ++b;

	// 컴파일 오류로 변경
	if (10 == a)
	{

	}
		
	// 구조체
	// 사용자가 직접 설계할 수 있는 자료형
	MyType  t;
	NewType t1;


	// 배열
	int iArr[10] = {};
	*(iArr + 2) = 3;

	// 0 ~ 9
	for (int i = 0; i < 10; ++i)
	{
		iArr[i] = i + 1;
	}

	int Input = 0;
	scanf_s("%d", &Input);

	const int const_input = 100;
	int iArray[const_input] = {};

	// 동적 할당
	int* pData = (int*)malloc(4 * Input);

	free(pData);

	return 0;
}