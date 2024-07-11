#include <stdio.h>

#include <windows.h>

// 전처리기
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


	// 비트 연산자( 정수타입 데이터에만 사용할 수 있는 연산자 )
	// <<, >>(비트 쉬프트)
	// 화살표가 가리키는 방향으로 비트를 지정한 숫자만큼 이동시킨다.		
	
	// &(곱), |(합), ^(xor), ~(비트반전)
	unsigned char c1 = 10;
	unsigned char c2 = 15;
	unsigned char c3 = 0;

	c3 = c1 & c2; // 둘다 1 이면 1
	c3 = c1 | c2; // 둘중 하나라도 1이면 1
	c3 = c1 ^ c2; // 같으면 0, 다르면 1
	c3 = ~c3;	  // 1 을 0으로, 0 을 1로 변환

	bool IsMinmun = false;
	bool IsSystemBtn = false;
	bool IsMovePossible = false;
	bool IsChangeSize = false;

	unsigned int State = 0;
	// 특정 비트자리에 값을 넣거나 (|), 비트값을 0으로 되돌리거나( &, ~)
	// 특정 비트자리에 비트값이 1이 있는지 확인(&)

	State |= ATT_UP;
	//State |= ICED;
	State |= HOLLY;

	if (State & ICED)
	{
		printf("동상상태이다.");
	}

	// 특정 자리 비트 제거
	State &= ~ICED;


	// 반복문



	return 0;
}