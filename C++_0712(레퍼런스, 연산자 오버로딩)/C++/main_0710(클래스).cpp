
#include <iostream>

// C++ 에서 class 와 struct 의 유일한 차이점은 
// Default 제한 지정자가 class 는 Private, struct 는 Public 이다

class MyType
{
	// 접근 제한 지정자
private:
	// 맴버 변수
	int		a;
	float	b;

	// 맴버 함수 - 특정 클래스, 구조체
	// 맴버함수를 호출하기 위해서, 객체가 필요하다.
public:
	void SetInt(int _a)
	{
		a = _a;
	}

	void SetFloat(float _f)
	{
		b = _f;
	}

	MyType* GetAdress()
	{
		return this;
	}

public:
	// 생성자 
	// - 맴버함수, 구현하지 않아도 자동 생성되는 맴버함수
	// - 객체가 생성될 때 호출
	MyType()
	{
		printf("생성자 호출됨\n");
	}

	// 소멸자 
	// - 맴버함수, 구현하지 않아도 자동 생성되는 맴버함수
	// - 객체가 삭제될 때 호출 됨
	~MyType()
	{
		printf("소멸자 호출됨\n");
	}
};

struct MyStruct
{
	int		a;
	float	b;
};

// 전역 함수
void SetInt(MyStruct* _this, int _a)
{
	_this->a = _a;
}


int main()
{
	// 사용자 정의 자료형
	// struct
	// class

	// C-struct -> C++-class
	// 은닉성, 맴버에 대한 접근레벨을 지정할 수 있게 됨
	MyType type = {};	
	MyType type1 = {};
	MyType type2 = {};

	//type.a = 100;
	//type.b = 200.f;

	type1.SetInt(100);
	type.SetFloat(200.f);

	MyType* pAdress = type.GetAdress();


	// C 에서의 동적할당
	// 단순하게 원하는 메모리의 크기만 전달하기 때문에, 힙메모리 공간에 할당되는 영역이 무슨 용도로 
	// 쓰일지까지 알 수가 없다.

	// 따라서 C++ 의 클래스(사용자정의자료형) 의 규칙인 객체 생성시 생성자 호출, 객체 소멸 시 
	// 소멸자 호출로 연계될 수 없다.
	MyType* pMyType	= (MyType*)malloc(sizeof(MyType) * 4);

	pMyType[0];
	pMyType[1];
	pMyType[2];
	pMyType[3];

	// C 에서의 힙메모리 해제
	free(pMyType);


	// C++ 에서의 동적할당
	// 동적할당에 사용할 자료형 정보를 전달
	// 자료형 정보를 통해서 크기정보와, 클래스 타입인 경우 클래스의 생성자 호출까지 연동할 수 있다.
	MyType* pMyType1 = new MyType;
	
	// C++ 에서의 힙메모리 해제
	// delete 키워드에 포인터를 전달시킴, 전달시키는 포인터가 어떤 타입이냐에 따라서 힙메모리 공간을
	// 어떤 용도로 썻는지 알 수 있음, 따라서 소멸자까지 호출이 가능
	delete pMyType1;


	// C++ 에서의 동적할당 여러개
	MyType* pMyType2 = new MyType[4];

	// C++ 에서의 힙메모리 해제
	delete[] pMyType2;


	return 0;
}