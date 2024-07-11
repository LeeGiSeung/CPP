#include <stdlib.h>
#include <stdio.h>

// 열거형
// 4바이트 정수
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
	// 4 바이트, 정수 타입
	// :: 범위지정, Scope
	STATE type = STATE::IDLE;
	type = STATE::MOVE;
	type = STATE::DASH;
	//type = 500;

	//int iState = IDLE;
	//iState = MOVE;
	//iState = 500;

	MONSTER_STATE monState = MONSTER_STATE::IDLE;

	// enum class 로 선언한 열거형은 일반 정수 변수에 값을 대입할 수 가 없어서 강제 캐스팅을 해주어야 한다.
	int i = (int)STATE::IDLE;


	// switch
	switch (2)
	{
	case 1:		
	case 2:
		printf("1번 케이스 or 2번 케이스");		
		break;
	default:
		printf("디폴트 케이스");
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