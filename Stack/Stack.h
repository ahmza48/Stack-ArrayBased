#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

//								Stack implementaion on Array

template <typename T> 
class Stack
{
private:
	T *stack;
	int size;
	int top;
public:
	//Stack();
	//Stack(int);
	//~Stack();
	//void push(T);
	//void pop();
	//T getTop();
	//void reSize();
	//bool isEmpty();
	//bool isFull();
	//void display();



	Stack() {
		stack = nullptr;
		size = 0;
		top = -1;
	};
	Stack(int s) {
		size = s;
		stack = new T[size];
		top = -1;
	};
	~Stack() {
		delete[] stack;
		stack = nullptr;
		top = -1;
		size = 0;
	};
	int getTop() {
		return top;
	};

	void push(T val) {
		if (isFull()) {
			resize();
			stack[++top] = val;
		}
		else {
			stack[++top] = val;
		}
	};
	void pop() {
		if (!isEmpty()) {
			top--;
		}
		else {
			cout << "Stack/Array is empty!" << endl;
		}
	};
	T getTopValue() {
		if(!isEmpty()) {
			return stack[top];
		}
	};
	void resize() {
		T*newArr = new T[2 * size];
		for (int i = 0; i < size && i<=top; i++)
		{
			newArr[i] = stack[i];
		}
		//~Stack();
		size = size * 2;
		delete[] stack;
		stack = newArr;
	};
	bool isFull() {
		if (top == size - 1)
			return true;
		return false;
	};
	bool isEmpty() {
		if (top == -1)
			return true;
		return false;
	};
	void display() {
		if (isEmpty()) {
			cout << "Stack is empty" << endl;
		}
		else {
			cout << "Elements in stack/array are:" << endl;
			for (int i = 0; i <=top; i++)
			{
				cout << stack[i] << " ";
			}
		}
	};


};
#endif
