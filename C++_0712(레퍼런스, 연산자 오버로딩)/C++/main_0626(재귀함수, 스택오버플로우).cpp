#include <stdio.h>

// ����(Local) ����


// ���(Recursion) �Լ�


void TestFunc_3()
{
	int c = 4;
}

void TestFunc_2()
{
	int b = 3;

	TestFunc_3();
}


void TestFunc_1()
{
	int a = 2;

	TestFunc_1();
}

int main()
{
	int Main = 1;
		
	TestFunc_1();

	return 0;
}

