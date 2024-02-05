// Pointer2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

struct Player {
	int hp;
	int attack;
};

int main()
{
	//  오늘의 주제 : 포인터 연산
//1) 주소 연산자 (&)
//2) 산술 연산자 + -
//3) 간접 연산자 *
//4) 간접 멤버 연산자

	int number = 1;

	//1) 주소 연산자를 이용해서 주소를 뽑아올 수 있었다.
	// 해당 변수의 주소를 알려주세요~

	//number라는 변수의 주소가 pointer에 들어간다.
	//더 정확히 말하면 해당 변수 타입(Type)에 따라서 Type*를 반환한다.
	int* pointer = &number;



	//2) 산술 연산자 (+ - 내용)
	//number = number + 1;
	number++; //1이 증가
	//++number;
	//number += number; 
	// 이런 문법들이 포인터에도 가능하다.


	//[!] 포인터에서 +나 -등 산술 연산으로 1을 더하거나 빼면
	// 정글 "그 숫자(1)"를 더하고 빼라는 의미가 아니다.
	// 한번에 Type 크기만큼을 이동하라! 라는 의미이다.
	// 다음/이전 바구니로 이동하고 싶다.[바구니 단위]의 이동
	// 즉 1을 더하면 바구니 1개 로 이동하라
	// 3을 더하면 바구니 3개 이동시켜라
	// 
	//pointer += 1;
	pointer++;//4가 증가


	//3) 간접 연산자(*)
	// 해당 주소로 이동해서 값을 변경한다.
	number = 3;
	*pointer = 3;

	Player player;
	player.hp = 100;
	player.attack = 10;

	Player* playerPtr = &player;

	(*playerPtr).hp = 200;
	(*playerPtr).attack = 10;

	// 4) 간접 멤버 연산자(->)
	// * 간접 연산자 (포탈 타고 해당 주소로 이동
	// . 구조체의 특정 멤버를 다룰때 사용(어셈블리 언어로 까보면 .은 사실 덧셈) 어떤 구조체의 멤버가 몇번 offset에 있는지
	// ->는 *와 .을 한번에!

	playerPtr->attack = 10;
	playerPtr->hp = 100;

	return 0;
}
