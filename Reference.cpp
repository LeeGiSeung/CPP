// Pointer2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;


struct Statinfo {
	int hp = 10; // + 0
	int attack 41; // + 4
	int defence = 50; // + 8
};

void PrintInfoByPtr(const Statinfo* info) {
	cout << "----------------" << endl;
	cout << info.hp << endl;
	cout << info.attack << endl;
	cout << info.defence << endl;
	cout << "------------------" << endl;
}

void PrintInfoByRef(const Statinfo& info) {
	cout << "----------------" << endl;
	cout << info.hp << endl;
	cout << info.attack << endl;
	cout << info.defence << endl;
	cout << "------------------" << endl;
}

//만약 값을 수정하지 않는다면 포인터를 사용하지 않더라도 문제는 없다.
// 1) 값 전달 방식(cout<<) 기존 복사 방식
// 2) 주소 전달 방식 (포인터이용)

// 값 전달 방식간 statinfo가 크면 클수록 부담이 엄청 커진다.
// 하지만 주소 전달 방식은 복사하지 않기 때문에 부담이 발생하지 않는다.

// 오늘 새롭게 배울 내용
// 3) 참조 전달
int main() {
	
	// 4바이트 정수형 바구니를 사용할거야.
	// 앞으로 그 바구니 이름을 num 
	int number = 1;

	// * 주소를 담는 바구니
	// int 그 바구니를 따라가면 int 데이터(바구니)가 있음

	int* pointer = &number;
	*pointer = 2;

	// 오늘 알아볼 참조도 포인터와 상당히 유사하다.

	//로우레벨 관점에서 실제 방식은 int*과 똑같음
	//하지만 사용방식은 1) 값 전달 방식과 비슷하다.
	int& reference = number;

	//cpp 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
	// number라는 바구니에 reference라는 다른 이름을 지어준다.
	//앞으로 reference 바구니에 뭘 꺼내거나 넣으면
	//number 바구니에 그 값을 넣으면 됨

	reference = 3;

	//reference 정리
	// 주소 전달 처럼 주소값을 이용해 원본을 건드린다.

	Statinfo info;

	PrintInfoByRef(info);

	//포인터 vs 참조
	//성능 : 똑같음
	//편의성 : 참조 승

	//1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만은 아니다.
	// 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있는데.
	// 참조는 알게모르게 지나칠 수 있다는 치명적인 오류가 있다.

	//포인터로 넘길때는 &를 사용해서 주소값을 넘겨주니 포인터인것을 알 수 있지만
	//참조는 &없이 넘겨주기에 이게 참조인지 아니면 복사해서 넘기는 것인지 구별이 안된다.
	//그래서 const를 사용해서 reference를 사용하더라도 값 수정이 되지 않게
	
	//포인터도 const사용 가능 
	//*기준으로 앞에 붙이느냐, 뒤에 붙이느냐에 따라 의미가 달라진다.
	
	//const 를 *뒤에 붙인다면?
	//info라는 바구니의 내용물(주소)를 바꿀 수 없는 상태
	//info = 주소값을 갖는 바구니 -> 이 주소값이 고정이다.
	//info = &globalinfo;

	//const를 *이전에 붙인다면?
	// info가 가르키고 있는 바구니의 내용물을 바꿀 수 없음
	//info->hp;
	
	// 경우에 따라 사용하면 되고 필요하면 const를 양쪽에 사용해도됨

	//2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름(별칭)
	// 이는 참조하는 대상이 없으면 안된다는 의미이다.
	// 유효한 대상을 무조건 가르키고 있어야 한다.

	Statinfo reference;
	//reference = info;
	PrintInfoByRef(reference);

	//만약 pointer에 null 값을 넣는다면? -> null을 받았다고 오류남
	Statinfo* pointer = nullptr;
	PrintInfoByPtr(pointer);
	// 이게 필요할 순간도 있다.
	// 특정 조건을 만족하지만 필요한게 없는 함수
	// 그래서 pointer를 사용할때는 info == nulptr인지 확인을 항상 해줘야한다. (!info)



	//그래서 결론은?
	//TeamByTeam
	//바뀌지 않고 읽는 용도로만 사용한다면 const ref&
	//그 외 일반적으로 ref (명시적으로 호출할때 OUT)을 붙인다. #define OUT 해야함

	return 0;
}

Statinfo* FindMonster() {
	//TODO HEAP영역에서 뭔가를 찾아봄
	//찾았다.
	// return monster;


}