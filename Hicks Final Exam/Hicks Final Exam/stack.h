#pragma once
#include <iostream>
#define MAX_STACK 5

template<typename T>
struct Node {
	T data;
	Node* link;
};

template<typename T>
class Stack {
private:
	Node<T>* top = NULL;
	int stack[MAX_STACK] = { 0, };
public:
	Stack() { 
	
	}
	~Stack() {  }

	Stack()

	void push(T value) {
		Node* ptr = new Node();
		ptr->data = value;
		ptr->link = top;
		top = ptr;
	}

	void pop() {
		if (isEmpty()) {
			std::cout << "Error: Stack is empty" << std::endl;
		}
		else {
			Node* ptr = top;
			top = top->link;
			delete(ptr);
		}
	}

	void showTop() {
		if (isEmpty()) {
			std::cout << "Stack is Empty";
		}
		else {
			std::cout << top->data;
		}
	}

	void swap(T* a, T* b) {
		char* temp;
		if (isEmpty()) {
			std::cout << "Stack is Empty";
		}
		else {
			temp = *a;
			*a = *b;
			*b = t;
		}
	}

	bool isEmpty() {
		if (top == NULL)
			return true;
		else
			return false;
	}

	bool isEmpty() {
		if (top == MAX_STACK - 1)
			return true;
		else
			return false;
	}
};