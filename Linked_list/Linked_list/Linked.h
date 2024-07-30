#pragma once

#include <iostream>

using namespace std;

template <typename T>
class DynamicArray {
private:
	//데이터
	T* Data;
	//메모리 크기
	int size;
	//할당된 메모리
	int capacity;

public:
	//생성자
	DynamicArray() : size(0), capacity(2) 
	{
		Data = new T[capacity];
	};
	//소멸자
	~DynamicArray() {
		delete[] Data;
	};
public:
	int Getsize();
	int Getcapacity();
	void SetSize(const int &input_size);
	void SetCapacity(const int &input_Capacity);

public:
	void pushback(const T& Data);
	void print();

private:
	void resize();
};

template<typename T>
int DynamicArray<T>::Getsize()
{
	return size;
}

template<typename T>
int DynamicArray<T>::Getcapacity()
{
	return capacity;
}

template<typename T>
inline void DynamicArray<T>::SetSize(const int& input_size)
{
	if (input_size <= 0)
		return;

	if (input_size > capacity) {
		SetCapacity(input_size);
	}
	size = input_size;

}

template<typename T>
inline void DynamicArray<T>::SetCapacity(const int& input_Capacity)
{
	if (input_Capacity > capacity) {
		T* newData = new T[input_Capacity];
		for (int i = 0; i < size; i++) {
			newData[i] = Data[i];
		}
		delete[] Data;
		Data = newData;
		capacity = input_Capacity;
	}
}

template<typename T>
inline void DynamicArray<T>::pushback(const T& iData)
{
	if (size == capacity) {
		resize();
	}
	Data[size++] = iData;
}

template<typename T>
inline void DynamicArray<T>::print()
{
	for (int i = 0; i < size; i++) {
		cout << Data[i] << "\n";
	}
}

template<typename T>
inline void DynamicArray<T>::resize()
{
	capacity *= 2;
	T* newData = new T[capacity];
	for (int i = 0; i < size; i++) {
		newData[i] = Data[i];
	}
	delete[] Data;
	Data = newData;

}

