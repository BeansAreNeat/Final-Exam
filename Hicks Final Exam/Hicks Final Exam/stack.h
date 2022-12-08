#pragma once
#include <iostream>
#define SIZE 5

/*
	Citations
	1) https://stackoverflow.com/questions/4880447/how-to-check-if-a-linked-list-is-full-using-java#:~:text=There%27s%20no%20such%20concept%20as%20a%20%22full%22%20linked,personally%20keep%20a%20count%20with%20the%20linked%20list.
	2) https://stackoverflow.com/questions/3928935/size-of-linked-list-in-c-function
*/

struct Node {
	int data;
	Node* link;
};


class Stack {
private:
	Node* top;
	
public:
	Stack() {
		Node* top = NULL;
	}

	Stack(Stack& top) {
	//	Node* top = NULL;
	}

	~Stack() {  }

	void push(int value) {
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

	int Top() {
		if (isEmpty()) {
			std::cout << "Error: Stack is empty" << std::endl;
			exit(3);
		}
		else {
			return top->data;
		}
	}

	void swap(int a, int b) {
		int temp;
		if (isEmpty()) {
			std::cout << "Stack is Empty";
		}
		else {
			temp = a;
			a = b;
			b = temp;
		}
	}

	int size() {
		int count = 0;
		Node* ptr = top;
		while (ptr != NULL) {
			++count;
			ptr = ptr->link;
		}
		return count;
	}

	bool isFull() {
		if (top == NULL && size() >= SIZE)
			return true;
		else
			return false;
	}

	bool isEmpty() {
		if (top != NULL)
			return true;
		else
			return false;
	}
};