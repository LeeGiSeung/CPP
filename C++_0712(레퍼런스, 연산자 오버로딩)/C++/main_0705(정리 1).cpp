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

	// �ڷ���
	// ����Ÿ��
	//  - signed(����, ���)
	//  - unsigned(���)
	
	// �Ǽ�Ÿ��
	// - float
	// - double
	float f = 0.f;
	double d = 1.11;
	f = (float)d;

	// ������
	// ++, --
	int b = 0;
	int a = ++b;

	// ������ ������ ����
	if (10 == a)
	{

	}
		
	// ����ü
	// ����ڰ� ���� ������ �� �ִ� �ڷ���
	MyType  t;
	NewType t1;


	// �迭
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

	// ���� �Ҵ�
	int* pData = (int*)malloc(4 * Input);

	free(pData);

	return 0;
}