#include <stdlib.h>

// �޸� ����
// 1. ���� (�Լ�, ��������)
// 2. ������ ( ���μ��� ���� ��, ���μ��� ���� ��)
//   - ��������, ��������, �ܺκ���
// 3. ROM ( Relad Only Memory )
//   - ���� ���� �ʱ�ȭ ������, ���ڿ� ������, �ڵ�
// 4. �� (Heap)
//   - �����Ҵ����� ��� ����

typedef int MYINT;

//#define MYINT int




int global[2000] = {};

int main()
{		
	int arr[100] = {};

	MYINT a = 0;

	// F12
	size_t size = 0;
	time_t time = 0;

	// �����Ҵ�
	int* pData = (int*) malloc(20);

	pData[0] = 10; // *(pData + 0)
	pData[1] = 20; // *(pData + 1)
	pData[2] = 30; // *(pData + 2)
	pData[3] = 40; // *(pData + 3)
	pData[4] = 50; // *(pData + 4)

	// �Ҵ����� ���� �������� �����͸� �̿��� �����ؼ� �����͸� ���(���) �� ���
	// Heap Corruption( �� �ջ� )
	pData[5] = 60; // *(pData + 4)
	pData[6] = 70; // *(pData + 4)

	// 1. �� �޸� ������ �Ҵ����� ���� ������ ����, �����͸� ���
	// 2. �Ҵ��� �� ������ ���� ��ȯ�� �̷������ ����
	//   - �޸� ����(Leak)

	free(pData);

	//int IArr[3] = {};
	//IArr[3] = 10;

	return 0;
}