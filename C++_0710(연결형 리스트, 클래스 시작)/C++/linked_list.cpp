#include "linked_list.h"

#include <stdlib.h>

void Push_Back(List* _List, int _Data)
{
	// 데이터를 저장할 수 있는 Node 를 동적할당하기
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->Data = _Data;
	pNewNode->pNext = nullptr;

	// 1. 입력된 데이터가 리스트의 첫번째인 경우
	if (0 == _List->Count)
	{
		_List->pHead = pNewNode;
	}

	// 2. 리스트가 1개 이상 데이터를 가지고 있는 경우
	else
	{
		// List 가 보유한 데이터(노드) 중 가장 마지막 노드를 찾아낸다.
		Node* pEndNode = _List->pHead;
		while (pEndNode->pNext) 
		{ 
			pEndNode = pEndNode->pNext; 
		}

		// 새로 들어온 데이터를 저장하고있는 노드를 가장 마지막노드가 가리키게 한다.
		pEndNode->pNext = pNewNode;
	}

	++_List->Count;
}



void Push_Front(List* _List, int _Data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == nullptr)
	{
		return;
	}
	pNewNode->Data = _Data;

	pNewNode->pNext = _List->pHead;
	_List->pHead = pNewNode;


	_List->Count++;
}

void Release(List* _List)
{
	if (nullptr == _List->pHead)
		return;

	/*Node* pNode = _List->pHead;
	while (pNode)
	{
		Node* pCurNode = pNode;
		pNode = pNode->pNext;
		free(pCurNode);
	}*/

	Node* pNode = _List->pHead;
	for (int i = 0; i < _List->Count; ++i)
	{
		Node* pCurNode = pNode;
		pNode = pNode->pNext;
		free(pCurNode);
	}

	_List->Count = 0;
	_List->pHead = nullptr;
}
