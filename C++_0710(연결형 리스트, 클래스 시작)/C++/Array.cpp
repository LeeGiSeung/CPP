#include "Array.h"

#include <stdlib.h>
#include <assert.h>

void Init(Array* _Arr)
{
	_Arr->Limit = 2;
	_Arr->Current = 0;
	_Arr->pData = (int*)malloc(sizeof(int) * _Arr->Limit);
}

int GetData(Array* _Arr, int _Idx)
{
	return _Arr->pData[_Idx];
}

void Push(Array* _Arr, int _Data)
{
	// 현재 동적할당한 공간이 꽉 찬 경우
	if (_Arr->Limit <= _Arr->Current)
	{
		Reserve(_Arr, _Arr->Limit * 2);
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

void SetData(Array* _Arr, int _Idx, int _Data)
{
	assert(_Idx < _Arr->Current);

	_Arr->pData[_Idx] = _Data;
}

// 공간을 미리 확보해둔다.
void Reserve(Array* _Arr, int _Size)
{
	// 기존 Limit 개수보다 더 적은 크기로 예약은 불가능
	assert(_Arr->Limit < _Size);

	// 기존 Limit 의 2배를 동적할당한다.
	int* pNewData = (int*)malloc(_Size * sizeof(int));

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
	_Arr->Limit = _Size;
}


void Resize(Array* _Arr, int _Size)
{
	// 기존 Limit 개수보다 더 적은 크기로 확장은 불가능
	assert(_Arr->Limit < _Size);

	// 기존 Limit 의 2배를 동적할당한다.
	int* pNewData = (int*)malloc(_Size * sizeof(int));

	// 기존 공간의 데이터를, 새로운 공간으로 이동시킨다.
	for (int i = 0; i < _Arr->Current; ++i)
	{
		pNewData[i] = _Arr->pData[i];
	}

	// 추가 확장한 공간을 0 으로 채훈다.
	for (int i = _Arr->Current; i < _Size; ++i)
	{
		pNewData[i] = 0;
	}


	// 기존 공간을 메모리 해제한다.
	free(_Arr->pData);

	// 동적배열이 새로운 공간을 가리키게 한다.
	_Arr->pData = pNewData;

	// 최대 개수를 갱신한다.
	_Arr->Limit = _Size;
	_Arr->Current = _Size;
}

