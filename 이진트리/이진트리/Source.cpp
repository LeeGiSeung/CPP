#include <iostream>

#include "Header.h"

int main() {
    // BST ��ü ����
    BST<int, float> myBst;

    // �� ���� Pair ��ü�� �����Ͽ� BST�� ����
    myBst.insert(Make_pair(50, 1.1f));
    myBst.insert(Make_pair(30, 2.2f));
    myBst.insert(Make_pair(70, 3.3f));
    myBst.insert(Make_pair(20, 4.4f));
    myBst.insert(Make_pair(40, 5.5f));
    myBst.insert(Make_pair(60, 6.6f));
    myBst.insert(Make_pair(80, 7.7f));

 

    return 0;
}