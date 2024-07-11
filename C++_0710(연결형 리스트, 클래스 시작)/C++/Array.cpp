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
	// ���� �����Ҵ��� ������ �� �� ���
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

// ������ �̸� Ȯ���صд�.
void Reserve(Array* _Arr, int _Size)
{
	// ���� Limit �������� �� ���� ũ��� ������ �Ұ���
	assert(_Arr->Limit < _Size);

	// ���� Limit �� 2�踦 �����Ҵ��Ѵ�.
	int* pNewData = (int*)malloc(_Size * sizeof(int));

	// ���� ������ �����͸�, ���ο� �������� �̵���Ų��.
	for (int i = 0; i < _Arr->Current; ++i)
	{
		pNewData[i] = _Arr->pData[i];
	}

	// ���� ������ �޸� �����Ѵ�.
	free(_Arr->pData);

	// �����迭�� ���ο� ������ ����Ű�� �Ѵ�.
	_Arr->pData = pNewData;

	// �ִ� ������ �����Ѵ�.
	_Arr->Limit = _Size;
}


void Resize(Array* _Arr, int _Size)
{
	// ���� Limit �������� �� ���� ũ��� Ȯ���� �Ұ���
	assert(_Arr->Limit < _Size);

	// ���� Limit �� 2�踦 �����Ҵ��Ѵ�.
	int* pNewData = (int*)malloc(_Size * sizeof(int));

	// ���� ������ �����͸�, ���ο� �������� �̵���Ų��.
	for (int i = 0; i < _Arr->Current; ++i)
	{
		pNewData[i] = _Arr->pData[i];
	}

	// �߰� Ȯ���� ������ 0 ���� ä�ƴ�.
	for (int i = _Arr->Current; i < _Size; ++i)
	{
		pNewData[i] = 0;
	}


	// ���� ������ �޸� �����Ѵ�.
	free(_Arr->pData);

	// �����迭�� ���ο� ������ ����Ű�� �Ѵ�.
	_Arr->pData = pNewData;

	// �ִ� ������ �����Ѵ�.
	_Arr->Limit = _Size;
	_Arr->Current = _Size;
}

