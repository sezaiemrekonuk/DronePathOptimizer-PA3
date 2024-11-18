#include "Stack.h"
#include <iostream>

// Constructor to initialize an empty stack
Stack::Stack() {
    // TODO: Your code here
	top = -1;
}

// Adds a province to the top of the stack
void Stack::push(int province) {
    // TODO: Your code here
	if (top < MAX_SIZE - 1) {
		data[++top] = province;
	}
	else {
		std::cout << "Can't add any provinces to stack, it is full!" << std::endl;
	}
}

// Removes and returns the top province from the stack
int Stack::pop() {
    // TODO: Your code here
	if (top >= 0) {
		return data[top--]; // I prefer to use soft remove.
	}
	else {
		std::cout << "Can't remove any provinces from stack, it is empty!" << std::endl;
	}
    return -1;
}

// Returns the top province without removing it
int Stack::peek() const {
    // TODO: Your code here
	if (top >= 0) {
		return data[top];
	}
	else {
		std::cout << "Can't peek any provinces from stack, it is empty!" << std::endl;
	}
    return -1;
}

// Checks if the stack is empty
bool Stack::isEmpty() const {
    // TODO: Your code here
    return top == -1;
}

// Function to get the current size of the stack
int Stack::getSize() const {
    // TODO: Your code here
    return top + 1;
}
