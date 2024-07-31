#include <iostream>

#include "Header.h"

int main() {
    // BST 객체 생성
    BST<int, float> myBst;

    // 몇 개의 Pair 객체를 생성하여 BST에 삽입
    myBst.insert(Make_pair(50, 1.1f));
    myBst.insert(Make_pair(30, 2.2f));
    myBst.insert(Make_pair(70, 3.3f));
    myBst.insert(Make_pair(20, 4.4f));
    myBst.insert(Make_pair(40, 5.5f));
    myBst.insert(Make_pair(60, 6.6f));
    myBst.insert(Make_pair(80, 7.7f));

 

    return 0;
}