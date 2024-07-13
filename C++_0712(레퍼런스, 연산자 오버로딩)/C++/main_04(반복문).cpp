#include <stdio.h>

int main()
{
	int i = 10;

	// 반복문

	{
		// while
		int i = 0;

		while (i < 10) // while 의 조건이 참 인 동안 반복문을 수행
		{
			printf("출력\n");
			++i;
		};
	}

	{
		// for 문
		int i = 0;

		// 첫번째 : 딱 한번 수행, 변수의 초기화 
		// 두번째 : 참, 거짓에 따른 반복문 수행여부
		// 세번째 : 반복문이 수행될때마다 한번씩 동작
		for (i = 0; i < 10 ;  ++i)
		{
			printf("출력\n");
		}
	}

	
	// 역순
	//for (int j = 0; j < 20; ++j)
	//{
	//	for (int i = 0; i < (20 - j); ++i)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}


	// 정삼각형
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