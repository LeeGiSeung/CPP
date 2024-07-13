#include <stdlib.h>
#include "Array.h"

// 


int main()
{
	Array arr = { };
	
	Init(&arr);
	Resize(&arr, 10);

	SetData(&arr, 6, 200);
	SetData(&arr, 3, 4500);

	//Push(&arr, 100);
	//Push(&arr, 200);
	//Push(&arr, 300);
	//Push(&arr, 400);
	//Push(&arr, 500);

	//Reserve(&arr, 4);

	int data = GetData(&arr, 0);
	
	Release(&arr);

	return 0;
}