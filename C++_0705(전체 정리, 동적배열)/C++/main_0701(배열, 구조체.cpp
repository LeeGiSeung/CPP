#include <stdio.h>

// �迭

// ����ü
struct MyDataType
{
	// �ɹ�
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
	// �迭(Array)
	int i0 = 0, i1 = 0, i2 = 0;

	// �迭�� ������, �ʱ�ȭ ���
	int iArr[10] = {  };
	
	// �迭�̸�[�ε���];
	iArr[0];
	iArr[1];
	iArr[9] = 100;

	// �� ������ �̸��� ������ ������ �ʿ䰡 ����.
	// �迭�� �޸𸮰� �������� ������ ������.


	// ����ü(Struct)
	// ����ڰ� ����� �ڷ���(User Define DataType)
	MyDataType data = {};
	data.i = 20;
	data.f = 3.14f;

	MyDataType data1;
	MyDataType data2;

	// �迭�� ����ü
	MyDataType arrData[10] = {};
	arrData[0].i = 1;
	arrData[0].f = 1.f;

	arrData[9].i = 10;
	arrData[9].f = 10.f;

	arrData[4].sArr[4] = 20;

	int size = sizeof(MyDataType);


	// ����ü ũ��


	return 0;
}