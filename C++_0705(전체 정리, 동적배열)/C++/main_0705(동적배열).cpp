#include <stdlib.h>

// �����迭 (�����迭)
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
	// ���� �����Ҵ��� ������ �� �� ���
	if (_Arr->Limit <= _Arr->Current)
	{
		// ���� Limit �� 2�踦 �����Ҵ��Ѵ�.
		int* pNewData = (int*)malloc(_Arr->Limit * 2 * sizeof(int));

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