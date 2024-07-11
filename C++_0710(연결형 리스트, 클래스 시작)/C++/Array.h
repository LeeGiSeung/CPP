#pragma once

// 동적배열 (가변배열)
struct Array
{
	int*	pData;
	int		Limit;
	int		Current;
};

void Init(Array* _Arr);
void Push(Array* _Arr, int _Data);
void Release(Array* _Arr);
void SetData(Array* _Arr, int _Idx, int _Data);
int GetData(Array* _Arr, int _Idx);
void Resize(Array* _Arr, int _Size);
void Reserve(Array* _Arr, int _Size);
