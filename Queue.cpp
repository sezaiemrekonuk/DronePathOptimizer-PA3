#include "Queue.h"
#include <iostream>

// Constructor to initialize an empty queue
Queue::Queue() {
	front = 0;
	rear = 0;
}

// Adds a province to the end of the queue
void Queue::enqueue(int province) {
    // Implement circular structure
    // Add the province
	if (isFull()){
		std::cout << "Queue is full" << std::endl;
		return;
	}

	data[rear] = province;
	rear = (rear + 1) % MAX_QUEUE_SIZE;
}

// Removes and returns the front province from the queue
int Queue::dequeue() {
	if (isEmpty()) {
		std::cout << "Queue is empty" << std::endl;
		return -1;
	}

	int province = data[front];
	front = (front + 1) % MAX_QUEUE_SIZE;
	return province;
}

// Returns the front province without removing it
int Queue::peek() const {
    return data[front];
}

// Checks if the queue is empty
bool Queue::isEmpty() const {
	return front == rear;
}

// Checks if the queue is full
bool Queue::isFull() const {
	return (rear + 1) % MAX_QUEUE_SIZE == front;
}

// Add a priority neighboring province in a way that will be dequeued and explored before other non-priority neighbors
void Queue::enqueuePriority(int province) {
	if (isFull()) {
		std::cerr << "Queue is full. Cannot enqueue priority element.\n";
		return;
	}
	front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	data[front] = province;
}
