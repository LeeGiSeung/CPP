#include "linked_list.h"

#include <stdlib.h>

void Push_Back(List* _List, int _Data)
{
	// �����͸� ������ �� �ִ� Node �� �����Ҵ��ϱ�
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->Data = _Data;
	pNewNode->pNext = nullptr;

	// 1. �Էµ� �����Ͱ� ����Ʈ�� ù��°�� ���
	if (0 == _List->Count)
	{
		_List->pHead = pNewNode;
	}

	// 2. ����Ʈ�� 1�� �̻� �����͸� ������ �ִ� ���
	else
	{
		// List �� ������ ������(���) �� ���� ������ ��带 ã�Ƴ���.
		Node* pEndNode = _List->pHead;
		while (pEndNode->pNext) 
		{ 
			pEndNode = pEndNode->pNext; 
		}

		// ���� ���� �����͸� �����ϰ��ִ� ��带 ���� ��������尡 ����Ű�� �Ѵ�.
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
