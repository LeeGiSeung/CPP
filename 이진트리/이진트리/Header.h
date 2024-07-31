#pragma once

enum NodeType {
    Parent,
    Left,
    Right,
    End
};

// 이진 트리의 매 노드
template <typename T1, typename T2>
struct Pair
{
    T1* Key;
    T2* Value;

    Pair()
        : Key(nullptr), Value(nullptr)
    {}

    Pair(const T1& _Key, const T2& _Value)
        : Key(new T1(_Key)), Value(new T2(_Value))
    {}

    ~Pair() {
        delete Key;
        delete Value;
    }
};

template <typename T1, typename T2>
struct Node
{
    Pair<T1, T2> pair;
    Node<T1, T2>* NodePtrs[End];

    Node()
        : pair(), NodePtrs{ nullptr, nullptr, nullptr, nullptr }
    {}

    Node(const Pair<T1, T2>& _Pair,
        Node* _Parent = nullptr,
        Node* _Left = nullptr,
        Node* _Right = nullptr)
        : pair(_Pair), NodePtrs{ _Parent, _Left, _Right, nullptr }
    {}
};

template <typename T1, typename T2>
struct BST
{
private:
    int size;
    Node<T1, T2>* RootNode;

public:
    BST() : size(0), RootNode(nullptr) {}  // 기본 생성자 추가

    void insert(const Pair<T1, T2>& _Pair);
};

template<typename T1, typename T2>
void BST<T1, T2>::insert(const Pair<T1, T2>& _Pair)
{
    Node<T1, T2>* PNewNode = new Node<T1, T2>(_Pair);

    if (nullptr == RootNode) {
        RootNode = PNewNode;
    }
    else {
        Node<T1, T2>* pNode = RootNode;
        NodeType DirType = NodeType::End;
        while (true) {
            if (*(PNewNode->pair.Key) > *(pNode->pair.Key)) {
                DirType = Right;
            }
            else if (*(PNewNode->pair.Key) < *(pNode->pair.Key)) {
                DirType = Left;
            }
            else {
                // Key가 동일한 경우, 처리 로직을 추가할 수 있습니다.
                break;
            }

            if (nullptr != pNode->NodePtrs[DirType]) {
                pNode = pNode->NodePtrs[DirType];
            }
            else {
                PNewNode->NodePtrs[Parent] = pNode;
                pNode->NodePtrs[DirType] = PNewNode;
                break;
            }
        }
    }
    ++size; // 트리의 크기를 증가
}

template<typename T1, typename T2>
Pair<T1, T2> Make_pair(const T1& _first, const T2& _Second) {
    return Pair<T1, T2>(_first, _Second);
}
