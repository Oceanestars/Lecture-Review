#include <iostream>

using namespace std;

struct doubleNode{
	int key;
	doubleNode* next;
	doubleNode* prev;
};

class DoublyLinkedList{
	private:
		doubleNode* head;
		doubleNode* tail;

	public:
		DoublyLinkedList(doubleNode* h) {
			head = h;
			doubleNode* tmp = head;
			while (tmp->next != NULL) {
				tmp = tmp->next;
			}
			tail = tmp;
		}
		
		// Reverse direction
		void reverseTraverse() {
			doubleNode* tmp = tail; //
			while (tmp != NULL) {
				cout << tmp->key;
				if (tmp->prev != NULL) cout << ", ";
				tmp = tmp->prev; //
			}
			cout << endl;
		}
		
		// Forward direction
		void traverse() {
			doubleNode* tmp = head;
			while (tmp != NULL) {
				cout << tmp->key;
				if (tmp->next != NULL) cout << ", ";
				tmp = tmp->next;
			}
			cout << endl;
		}

		// Reverse
		doubleNode* reverseSearch(int searchKey){
			doubleNode* tmp = tail; //
			doubleNode* returnNode = NULL;
			bool found = false;

			while (!found && (tmp != NULL)) {
				if (tmp->key == searchKey) {
					found = true;
					returnNode = tmp;
				} else {
					tmp = tmp->prev; //
				}
			}

			return returnNode;
		}

		// Forward
		doubleNode* search(int searchKey){
			doubleNode* tmp = head;
			doubleNode* returnNode = NULL;
			bool found = false;

			while (!found && (tmp != NULL)) {
				if (tmp->key == searchKey) {
					found = true;
					returnNode = tmp;
				} else {
					tmp = tmp->next;
				}
			}

			return returnNode;
		}

		void insertNode(int* prevValue, doubleNode* newNode) {
			// Insert at head
			if (prevValue == NULL) {
				newNode->next = head;
				head = newNode;
				head->next->prev = head;
			// Insert at middle or tail
			} else { 
				doubleNode* tmp = head;
				while (tmp->key != *prevValue && tmp != NULL) {
					tmp = tmp->next;
				}
				newNode->next = tmp->next;
				newNode->prev = tmp;
				tmp->next = newNode;
				if (newNode->next != NULL) { // in the middle
					newNode->next->prev = newNode;
				} else { // at the tail
					tail = newNode;
				}
			}
		}

		void deleteNode(int searchKey) {
			// If head contains searchKey
			doubleNode* tmp;
			if (head->key == searchKey) {	
				tmp = head;
				head = head->next; // move the head
				tmp->next = NULL; // tmp is old head, reset pointers
				head->prev = NULL;
			// Else it's in the middle
			} else {
				doubleNode* left = head;
				doubleNode* deleting = left->next;
				while ((deleting->next != NULL) && (deleting->key != searchKey)) {
					left = left->next;
					deleting = deleting->next;
				}
				if (deleting->key == searchKey) {
					left->next = deleting->next;
					deleting->next = NULL;
					deleting->prev = NULL;
					if (left->next != NULL) { // node is in middle
						left->next->prev = left;
					} else { // node is the tail
						tail = left;
					}
				}
			}
		}
};

int main() {
	doubleNode head;
	head.key = 5;
	head.next = NULL;
	head.prev = NULL;

	doubleNode a;
	a.key = 6;
	a.next = NULL;
	a.prev = NULL;

	doubleNode b;
	b.key = 7;
	b.next = NULL;
	b.prev = NULL;
	
	// Initialize linked list
	head.next = &a;
	a.prev = &head;
	a.next = &b;
	b.prev = &a;

	// Initialize object
	DoublyLinkedList list(&head);
	cout << "Initial: \n";
	list.traverse();
	list.reverseTraverse();

	// Test delete
	cout << "Delete: \n";
	list.deleteNode(6);
	list.traverse();
	list.reverseTraverse();

	// Test insert
	cout << "Insert: \n";
	int key = 7;
	doubleNode c;
	c.key = 4;
	c.prev = NULL;
	c.next = NULL;
	// Insert 4 at the head
	list.insertNode(NULL, &c);
	list.traverse();
	list.reverseTraverse();
	// Insert 6 in the middle
	list.insertNode(&key, &a);
	list.traverse();
	list.reverseTraverse();

	return 0;
}