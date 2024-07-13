


// 메모리 복사 함수
void CopyData(void* _Dest, void* _Src, unsigned int _Size)
{
	unsigned char* pDest = (unsigned char*)_Dest;
	unsigned char* pSrc = (unsigned char*)_Src;	

	for (int i = 0; i < _Size; ++i)
	{
		//*(pDest + i) = *(pSrc + i);
		pDest[i] = pSrc[i];
	}
}


short Test()
{
	short arrShort[20] = {};

	for (int i = 0; i < 20; ++i)
	{
		arrShort[i] = i + 1;
	}

	int* pInt = (int*)arrShort;
	pInt += 4;

	//short* pShort = (short*)pInt;
	//return  *pShort;
	return *((short*)pInt);
}


void Add(int _a, int _b, int* _Out)
{
	*_Out = _a + _b;
}

int main()
{
	int c = 0;
	Add(1000, 1500, &c);


	short value = Test();

	short* pShort = nullptr;
		
	// 배열
	// 메모리가 연속됨
	int Array[10] = {};

	Array[0] = 10;
	Array[1] = 20;

	*(Array + 0) = 10;
	*(Array + 1) = 20;

	int* pInt = Array;	
	pInt[9] = 100;

	float f = 1.6f;
	pInt = (int*) &f;	
	int data = *pInt;

	{
		int i = 1000;
		float* pFloat = (float*)&i;
		float f = *pFloat;
	}

	{
		int arrSrc[5] = { 5,6,7,8,9 };
		int arrDesc[5] = {};

		CopyData(arrDesc, arrSrc, sizeof(arrDesc));

		char* pChar = nullptr;
		int size = sizeof(pChar);


		int a = 200;
		int b = 0;

		CopyData(&b, &a, sizeof(int));
	}



	return 0;
}