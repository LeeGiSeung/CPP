#include <stdlib.h>
#include <stdio.h>

// ������
// 4����Ʈ ����
enum class STATE
{
	IDLE,	
	MOVE,	
	DASH,	
	ATTACK,
	DODGE,
	JUMP,
};

enum class MONSTER_STATE
{
	IDLE,
	MOVE,
	ATTACK,	
};


//#define IDLE 0
//#define MOVE 1



int main()
{
	// 4 ����Ʈ, ���� Ÿ��
	// :: ��������, Scope
	STATE type = STATE::IDLE;
	type = STATE::MOVE;
	type = STATE::DASH;
	//type = 500;

	//int iState = IDLE;
	//iState = MOVE;
	//iState = 500;

	MONSTER_STATE monState = MONSTER_STATE::IDLE;

	// enum class �� ������ �������� �Ϲ� ���� ������ ���� ������ �� �� ��� ���� ĳ������ ���־�� �Ѵ�.
	int i = (int)STATE::IDLE;


	// switch
	switch (2)
	{
	case 1:		
	case 2:
		printf("1�� ���̽� or 2�� ���̽�");		
		break;
	default:
		printf("����Ʈ ���̽�");
		break;
	}

	int data = 1;
	if (1 == data || 2 == data)
	{

	}

	STATE myState = STATE::IDLE;
	switch (myState)
	{
	case STATE::IDLE:

		break;
	case STATE::MOVE:

		break;
	case STATE::DASH:

		break;
	case STATE::ATTACK:

		break;
	case STATE::DODGE:

		break;
	case STATE::JUMP:

		break;	
	}


	myState = STATE::IDLE;




	return 0;
}