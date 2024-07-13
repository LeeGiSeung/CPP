#pragma once

// ������ ����Ʈ
// �����͸� �߰���ġ�� �����ϰų� �����ϴ°�� ���� ������. O(1) ��� �ð���
// Ư�� �ε����� ����� �����Ϳ� �����Ҷ� ȿ���� ������. O(n) 

// ���� �迭�� �����͸� �߰��� �����ϰų� �����Ҷ� �־��� ��� n ���� ������ ���簡 �Ͼ��. O(n)
// �Է��� �����͸� �ε����� �����Ҷ� ���� ������. O(1)

// �Է��� �����͸� Ž��
// ����Ʈ, �����迭 ����Ž��
// ����Ž��Ʈ�� O(logN), �ؽ� ���̺� O(1) �� ����

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




