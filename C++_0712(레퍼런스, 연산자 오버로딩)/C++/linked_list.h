#pragma once

// 연결형 리스트
// 데이터를 중간위치에 삽입하거나 삭제하는경우 가장 빠르다. O(1) 상수 시간대
// 특정 인덱스로 저장된 데이터에 접근할때 효율이 느리다. O(n) 

// 동적 배열은 데이터를 중간에 삽입하거나 삭제할때 최악의 경우 n 번의 데이터 복사가 일어난다. O(n)
// 입력한 데이터를 인덱스로 접근할때 가자 빠르다. O(1)

// 입력한 데이터를 탐색
// 리스트, 동적배열 순차탐색
// 이진탐색트리 O(logN), 해시 테이블 O(1) 이 유리

struct Node
{
	int		Data;
	Node*	pNext;
};

struct List
{
	Node*	pHead;
	int		Count;
};

void Push_Back(List* _List, int _Data);
void Push_Front(List* _List, int _Data);
void Release(List* _List);




