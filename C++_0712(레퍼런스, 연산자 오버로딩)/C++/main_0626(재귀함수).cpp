#include <stdio.h>

// 4! = 4 * 3 * 2 * 1
// 10! = 10 * 9 * 7 .... * 1
int Factorial(int _Input)
{
	int Value = 1;

	for (int i = 0; i < (_Input-1); ++i)
	{
		Value *= (i + 2);
	}

	return Value;
}

// 재귀함수
int Factorial_Recursion(int _Input)
{
	if (1 == _Input)
	{
		return 1;
	}
	else
	{
		return Factorial_Recursion(_Input - 1) * _Input;
	}
}



// 피보나치 수열
// 1 1 2 3 5 8 13 21 34 55 ...
int Fibonacci(int _Input)
{
	if (1 == _Input || 2 == _Input)
	{
		return 1;
	}

	int Prev1 = 1;
	int Prev2 = 1;
	int Value = 0;

	for (int i = 0; i < _Input - 2; ++i)
	{
		Value = Prev1 + Prev2;
		Prev1 = Prev2;
		Prev2 = Value;
	}

	return Value;
}


int Fibonacci_Recursion(int _Input)
{
	if (1 == _Input || 2 == _Input)
		return 1;

	return Fibonacci_Recursion(_Input - 1) + Fibonacci_Recursion(_Input - 2);
}


int main()
{
	int Data = Factorial(6);
	Data = Factorial_Recursion(3);
	Data = Fibonacci(20);
	Data = Fibonacci_Recursion(20);

	return 0;
}