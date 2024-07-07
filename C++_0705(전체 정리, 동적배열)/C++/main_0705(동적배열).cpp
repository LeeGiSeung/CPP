#include <stdlib.h>

// 동적배열 (가변배열)
struct Array
{
	int*	pData;
	int		Limit;
	int		Current;
};

void Init(Array* _Arr)
{
	_Arr->Limit = 2;
	_Arr->Current = 0;
	_Arr->pData = (int*)malloc(sizeof(int) * _Arr->Limit);
}

void Push(Array* _Arr, int _Data)
{
	// 현재 동적할당한 공간이 꽉 찬 경우
	if (_Arr->Limit <= _Arr->Current)
	{
		// 기존 Limit 의 2배를 동적할당한다.
		int* pNewData = (int*)malloc(_Arr->Limit * 2 * sizeof(int));

		// 기존 공간의 데이터를, 새로운 공간으로 이동시킨다.
		for (int i = 0; i < _Arr->Current; ++i)
		{
			pNewData[i] = _Arr->pData[i];
		}

		// 기존 공간을 메모리 해제한다.
		free(_Arr->pData);

		// 동적배열이 새로운 공간을 가리키게 한다.
		_Arr->pData = pNewData;

		// 최대 개수를 갱신한다.
		_Arr->Limit *= 2;
	}

	_Arr->pData[_Arr->Current++] = _Data;	
}


void Release(Array* _Arr)
{
	free(_Arr->pData);

	_Arr->pData = nullptr;
	_Arr->Limit = 0;
	_Arr->Current = 0;
}


int main()
{
	Array arr = { };

	Init(&arr);

	Push(&arr, 100);
	Push(&arr, 200);
	Push(&arr, 300);
	Push(&arr, 400);
	Push(&arr, 500);

	Release(&arr);

	return 0;
}