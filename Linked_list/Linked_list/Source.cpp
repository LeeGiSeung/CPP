#include <stdlib.h>
#include <assert.h>
#include <iostream>

#include "Linked.h"

using namespace std;

int main() {

	DynamicArray<int> da;

	da.pushback(1);
	da.pushback(2);
	da.pushback(3);

	cout << "Capacity " << da.Getcapacity() << "\n";
	cout << "Size " << da.Getsize() << "\n";

	da.print();

	return 0;
}