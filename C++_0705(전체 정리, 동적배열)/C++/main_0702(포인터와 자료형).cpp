


struct MyDataType
{
	int		i;
	float	f;
};




int main()
{
	// �����Ϳ� �ڷ���
	int* p = nullptr;
	int num = 0;
	p = &num;
	
	short s = 0;
	short* pShort = &s;

	char* pChar = nullptr;

	// ������ ���� ����
	// �ڷ���* ������;
	// ����� �ۼ��� �ڷ��� Ÿ���� ������ �ּҸ� ���� �� �ִ�.
	// ������ ������ �Էµ� �ּҰ��� ���� ������ � Ÿ������ �ּҸ����δ� �� ���� ����.
	// ���� ������ ������ ����� �ڽſ��� �Էµ� �ּҰ� � ������ �ؼ��� ���� �̸� ���صд�.

	// void ������
	void* pVoid = nullptr;

	int a = 0;
	char c = 0;
	short ss = 0;

	pVoid = &a;
	pVoid = &c;
	pVoid = &ss;

	// void ������ ������ ����ִ� �ּҰ��� �ٸ� �Ϲ� �����Ϳ� �ű� �� ����.
	//int* pIntPtr = pVoid;

	
	// �����Ϳ� ����ü
	MyDataType data = {};
	MyDataType* pData = &data;

	(*pData).i = 10;
	(*pData).f = 1.1f;

	pData->i = 10;
	pData->f = 1.1f;

	data.i = 10;
	data.f = 1.1f;

	// �����Ϳ� �迭
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