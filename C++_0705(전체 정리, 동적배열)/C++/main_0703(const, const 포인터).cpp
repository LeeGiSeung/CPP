
#include <stdio.h>


struct NewDataType
{
	long long arr[500];
};

// NewDataType �� 4õ ����Ʈ �ڷ���,
// ���� �������� ũ�� ������, �����͸� ���� �����̶��, const ������ Ÿ������ �����ؼ�
// ������ �������� �����鼭, �����ͷ� �����͸� ���� �������� �˸���.
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


	// const Ű����
	// constant ���
	// r-value ���
	// l-value ����
	volatile const int data = 200;
	printf("%d\n", data);

	// const �� ���� ������ ����� ��� ��.
	// �ʱ�ȭ ������ ���� �ѹ��� ������ �� ����
	// ���� �ѹ��� ���� �����ϰ�, ������� �ʱ� �ٶ�� ���
		
	// const + ������
	int* pInt = (int*) &data;
	*pInt = 100;

	// ����(ġȯ) 
	printf("%d\n", data);



	// const *
	// * const
	const int Num = 1000;
	const int* pNum = &Num;
	
	// 1. const * 
	// - �������� ����� ���ȭ(����Ű�� ���� ���� �� ���� �Ұ�)
	// - �ٸ� ������ �ּҸ� �Է¹��� �� ����
	const int*  IntcPtr = nullptr;

	// 2. * const 
	// - ������ ������ ���ȭ ( ó���� �ʱ�ȭ ���� )
	// - ����Ű�� �ִ� ���� ������ �� �ִ�.
	int* const  IntPtrc = nullptr;

	// 3. const * const
	// - ���, ���� ���ȭ
	// - ó���� �ѹ��� �ּҰ��� ���� �� �ְ�, ���� �ּҿ� ���� �� ���� �Ұ�
	const int* const IntcPtrc = &Num;
	
	
	return 0;
}