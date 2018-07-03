#include <iostream>

using namespace std;

class Queue{
	private:
		int head, tail;
		int* data;
		int queueSize, maxQueue;

		// Private Methods
		bool isEmpty() {
			return true ? (queueSize == 0) : false;
		}

		bool isFull() {
			return true ? (queueSize == maxQueue) : false;
		}

	public:
		Queue(int maxSize) {
			head = 0;
			tail = 0;
			queueSize = 0;
			maxQueue = maxSize;
			data = new int[maxQueue];
		}
		~Queue() {
			delete[] data;
		}

		int enqueue(int value) {
			if ( isFull() ) return -1;
			data[tail] = value; // insert the new data
			queueSize++; // increment the queueSize
			if (tail == maxQueue-1) { // decide how to increment tail
				tail = 0;
			} else {
				tail++;
			}
			return 0;
		}

		int* dequeue() {
			if ( isEmpty() ) return NULL;
			queueSize--; // take an element away
			if (head == maxQueue-1) { // Decide where the head moves
				head = 0;
				return &data[maxQueue-1]; // return the data
			} else {
				return &data[head++];// return the data
			}
		}
};

int main() {
	Queue q(10);

	// Test enqueue and dequeue
	cout << "Enqueing!\n";
	for (int i=0; i<10; i++) { // fill the queue
		int returned = q.enqueue(i);
		if (returned == -1) {
			cout << "\tQueue is full!\n";
		} else {
			cout << "\tEnqueued: " << i << endl;
		}
	}

	int* ret = q.dequeue(); // empty a spot
	if (ret == NULL) {
		cout << "\tQueue is empty!\n";
	} else {
		cout << "\tDequeued: " << *ret << endl;
	}

	int returned = q.enqueue(10); // fill the new empty spot (Index=0)
	if (returned == -1) {
		cout << "\tQueue is full!\n";
	} else {
		cout << "\tEnqueued: " << 10 << endl;
	}

	cout << "Dequeing!\n";
	for (int i=0; i<11; i++) {
		ret = q.dequeue();
		if (ret == NULL) {
			cout << "\tQueue is empty!\n";
		} else {
			cout << "\tDequeued: " << *ret << endl;
		}
	}
	
	return 0;
}