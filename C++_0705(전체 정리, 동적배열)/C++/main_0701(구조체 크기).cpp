#include <stdio.h>

// �޸� ������ 1����Ʈ �ּҴ����� ��������
//#pragma pack(1)


// ����ü ũ��
// ���� ū �ɹ��� �ڷ����� �������� �޸� ����
struct My
{
	int i;
	float s;
	char arr[5];
};

struct NewType
{
	float f[2];
};

int main()
{
	int size = sizeof(My);

	NewType type = {};

	return 0;
}