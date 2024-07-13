
#include <stdio.h>


struct NewDataType
{
	long long arr[500];
};

// NewDataType 은 4천 바이트 자료형,
// 따라서 복사비용이 크기 때문에, 데이터를 읽을 목적이라면, const 포인터 타입으로 선언해서
// 원본을 수정하지 않으면서, 포인터로 데이터를 읽을 목적임을 알린다.
void OutputData(const NewDataType* _Data)
{
	// _Data->arr[0] = 100;

	// NewDataType* pData = (NewDataType*)_Data;
	
	for (int i = 0; i < 500; ++i)
	{
		printf("%d\n", _Data->arr[i]);
	}	
}


int main()
{
	NewDataType d = {};
	d.arr[0] = 100;
	
	OutputData(&d);


	// const 키워드
	// constant 상수
	// r-value 상수
	// l-value 변수
	volatile const int data = 200;
	printf("%d\n", data);

	// const 가 붙은 변수는 상수로 취급 됨.
	// 초기화 시점에 값을 한번만 세팅할 수 있음
	// 최초 한번만 값을 세팅하고, 변경되지 않길 바라는 경우
		
	// const + 포인터
	int* pInt = (int*) &data;
	*pInt = 100;

	// 포맷(치환) 
	printf("%d\n", data);



	// const *
	// * const
	const int Num = 1000;
	const int* pNum = &Num;
	
	// 1. const * 
	// - 포인터의 기능을 상수화(가리키는 곳을 접근 후 수정 불가)
	// - 다른 변수의 주소를 입력받을 수 있음
	const int*  IntcPtr = nullptr;

	// 2. * const 
	// - 포인터 변수가 상수화 ( 처음만 초기화 가능 )
	// - 가리키고 있는 곳을 수정할 수 있다.
	int* const  IntPtrc = nullptr;

	// 3. const * const
	// - 기능, 변수 상수화
	// - 처음에 한번만 주소값을 받을 수 있고, 받은 주소에 접근 후 수정 불가
	const int* const IntcPtrc = &Num;
	
	
	return 0;
}