#include <stdio.h>

static int g_Static = 0;
extern int RealGlobalValue;

int Pow(int _Num, int _Squared)
{
	int Value = _Num;

	for (int i = 0; i < _Squared - 1; ++i)
	{
		Value *= _Num;
	}

	printf("Hellow\n");

	g_Static = 2000;
	RealGlobalValue = 2000;
	return Value;
}


int Add(int _1, int _2)
{
	return _1 + _2;
}

int Sub(int _1, int _2)
{
	return _1 - _2;
}