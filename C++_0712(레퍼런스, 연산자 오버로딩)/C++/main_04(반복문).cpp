#include <stdio.h>

int main()
{
	int i = 10;

	// �ݺ���

	{
		// while
		int i = 0;

		while (i < 10) // while �� ������ �� �� ���� �ݺ����� ����
		{
			printf("���\n");
			++i;
		};
	}

	{
		// for ��
		int i = 0;

		// ù��° : �� �ѹ� ����, ������ �ʱ�ȭ 
		// �ι�° : ��, ������ ���� �ݺ��� ���࿩��
		// ����° : �ݺ����� ����ɶ����� �ѹ��� ����
		for (i = 0; i < 10 ;  ++i)
		{
			printf("���\n");
		}
	}

	
	// ����
	//for (int j = 0; j < 20; ++j)
	//{
	//	for (int i = 0; i < (20 - j); ++i)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}


	// ���ﰢ��
	int iRow = 20;

	for (int j = 0; j < iRow; ++j)
	{
		for (int k = 0; k < iRow - (j+1); ++k)
		{
			printf(" ");
		}

		for (int i = 0; i < (j + 1); ++i)
		{
			printf("* ");
		}
		printf("\n");
	}

	return 0;
}