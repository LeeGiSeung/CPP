#include <stdio.h>

#include <windows.h>

// ��ó����
#define ATT_UP		0x1
#define DEF_UP		0x2
#define DEX_UP		0x4
#define AGI_UP		0x8

#define FIRED		0x10
#define ICED		0x20
#define POISION		0x40
#define BLEED		0x80

#define HOLLY		(ATT_UP | DEF_UP | DEX_UP)



int main()
{
	int k = 100;


	// ��Ʈ ������( ����Ÿ�� �����Ϳ��� ����� �� �ִ� ������ )
	// <<, >>(��Ʈ ����Ʈ)
	// ȭ��ǥ�� ����Ű�� �������� ��Ʈ�� ������ ���ڸ�ŭ �̵���Ų��.		
	
	// &(��), |(��), ^(xor), ~(��Ʈ����)
	unsigned char c1 = 10;
	unsigned char c2 = 15;
	unsigned char c3 = 0;

	c3 = c1 & c2; // �Ѵ� 1 �̸� 1
	c3 = c1 | c2; // ���� �ϳ��� 1�̸� 1
	c3 = c1 ^ c2; // ������ 0, �ٸ��� 1
	c3 = ~c3;	  // 1 �� 0����, 0 �� 1�� ��ȯ

	bool IsMinmun = false;
	bool IsSystemBtn = false;
	bool IsMovePossible = false;
	bool IsChangeSize = false;

	unsigned int State = 0;
	// Ư�� ��Ʈ�ڸ��� ���� �ְų� (|), ��Ʈ���� 0���� �ǵ����ų�( &, ~)
	// Ư�� ��Ʈ�ڸ��� ��Ʈ���� 1�� �ִ��� Ȯ��(&)

	State |= ATT_UP;
	//State |= ICED;
	State |= HOLLY;

	if (State & ICED)
	{
		printf("��������̴�.");
	}

	// Ư�� �ڸ� ��Ʈ ����
	State &= ~ICED;


	// �ݺ���



	return 0;
}