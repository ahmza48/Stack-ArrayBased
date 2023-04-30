//#include "Stack.h"
//#include <iostream>
//using namespace std;
//template <typename T>
//Stack<T>::Stack() {
//	stack = nullptr;
//	size = 0;
//	top = -1;
//}
//template <typename T>
//Stack<T>::Stack(int s) {
//	size = s;
//	stack = new T[size];
//	top = -1;
//}
//template <typename T>
//Stack<T>::~Stack() {
//	delete[] stack;
//	stack = nullptr;
//}
//template <typename T>
//void Stack<T>::push(T val) {
//	if (isFull()) {
//		reSize();
//		stack[++top] = val;
//	}
//	else {
//		stack[++top] = val;
//	}
//}
//template <typename T>
//void Stack<T>::pop() {
//	if (!isEmpty) {
//		top--;
//	}
//	else {
//	cout << "Stack/Array is empty!" << endl;
//	}
//}
//template <typename T>
//T Stack<T>::getTop() {
//	if (!isEmpty) {
//		return stack[top];
//	}
//}
//template <typename T>
//void Stack<T>::reSize() {
//	T*newArr = new T[2 * size];
//	for (int i = 0; i < size; i++)
//	{
//		newArr[++top] = stack[i];
//	}
//	~Stack();
//	size = size * 2;
//	stack = newArr;
//}
//template <typename T>
//bool Stack<T>::isFull() {
//	if (top == size-1)
//		return true;
//	return false;
//}
//template <typename T>
//bool Stack<T>::isEmpty() {
//	if (top == -1)
//		return true;
//	return false;
//}
//template <typename T>
//void Stack<T>::display() {
//	if (isEmpty()) {
//		cout << "Stack is empty" << endl;
//	}
//	else {
//		cout << "Elements in stack/array are:" << endl;
//		for (int i = 0; i <=top; i++)
//		{
//			cout << stack[i] << " ";
//		}
//	}
//}