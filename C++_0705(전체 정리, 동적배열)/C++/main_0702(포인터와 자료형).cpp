


struct MyDataType
{
	int		i;
	float	f;
};




int main()
{
	// 포인터와 자료형
	int* p = nullptr;
	int num = 0;
	p = &num;
	
	short s = 0;
	short* pShort = &s;

	char* pChar = nullptr;

	// 포인터 변수 선언
	// 자료형* 변수명;
	// 선언시 작성한 자료형 타입의 변수의 주소만 받을 수 있다.
	// 포인터 변수에 입력된 주소값의 원본 변수가 어떤 타입인지 주소만으로는 알 수가 없다.
	// 따라서 포인터 변수는 선언시 자신에게 입력된 주소가 어떤 변수로 해석을 하지 미리 정해둔다.

	// void 포인터
	void* pVoid = nullptr;

	int a = 0;
	char c = 0;
	short ss = 0;

	pVoid = &a;
	pVoid = &c;
	pVoid = &ss;

	// void 포인터 변수에 들어있는 주소값을 다른 일반 포인터에 옮길 수 없다.
	//int* pIntPtr = pVoid;

	
	// 포인터와 구조체
	MyDataType data = {};
	MyDataType* pData = &data;

	(*pData).i = 10;
	(*pData).f = 1.1f;

	pData->i = 10;
	pData->f = 1.1f;

	data.i = 10;
	data.f = 1.1f;

	// 포인터와 배열
	{
		float* pFloat = nullptr;
		pFloat += 1;

		long long* pLongLong = nullptr;
		pLongLong += 1;

		char* pChar = nullptr;
		pChar += 1;

		short* pShort = nullptr;
		pShort += 1;

		int* pInt = nullptr;
		pInt += 1;

		void* pVoid = nullptr;
		//pVoid += 1;
	}

	return 0;
}