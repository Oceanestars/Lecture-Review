#include <iostream>

using namespace std;

class Stack {
	private:
		int top;
		int maxSize;
		int* data;

	public:
		Stack(int size){
			top = -1;
			maxSize = size;
			data = new int[maxSize];
		}
		~Stack() {
			delete[] data;
		}

		// is our stack full?
		bool isFull() {
			return true ? (top == maxSize-1) : false;
		}
		// is our stack empy?
		bool isEmpty() {
			return true ? (top == -1) : false;
		}

		// Push item onto stack
		int push(int value) {
			if( isFull() ) {
				return -1;
			}
			data[++top] = value;
			return 0;
		}

		// Pop an item from stack
		int* pop() {
			if ( isEmpty() ){
				return NULL;
			}
			return &data[top--];
		}
};

int main() {
	cout.setf(ios_base::boolalpha); // make true/false print pretty
	Stack myStack(10);

	// Test empty and full
	cout << "Full? " << myStack.isFull() << endl;
	cout << "Empty? " <<  myStack.isEmpty() << endl;

	// Test push
	cout << "Push: \n";
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	cout << "\tFull? " << myStack.isFull() << endl;
	cout << "\tEmpty? " <<  myStack.isEmpty() << endl;

	// Test pop
	cout << "Pop: \n";
	int* ret = myStack.pop();
	if (ret == NULL) {
		cout << "\tpop returned NULL\n";
	} else {
		cout << "\tpop returned " << *ret << endl;
	}

	ret = myStack.pop();
	if (ret == NULL) {
		cout << "\tpop returned NULL\n";
	} else {
		cout << "\tpop returned " << *ret << endl;
	}

	cout << "\tFull? " << myStack.isFull() << endl;
	cout << "\tEmpty? " <<  myStack.isEmpty() << endl;


	return 0;
}