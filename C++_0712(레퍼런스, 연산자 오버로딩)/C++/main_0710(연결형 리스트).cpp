#include "linked_list.h"

int main()
{
	List mylist = {};

	Push_Back(&mylist, 100);
	Push_Back(&mylist, 200);
	Push_Back(&mylist, 300);

	Release(&mylist);





	return 0;
}

// 240710 과제
// linked_list Push_Front 함수 구현해보기