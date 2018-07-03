#include <iostream>

using namespace std;

struct singleNode{
	int key;
	singleNode* next;
};

class SinglyLinkedList{
	private:
		singleNode* head;

	public:
		SinglyLinkedList(singleNode* h) {
			head = h;
		}
		
		void traverse() {
			singleNode* tmp = head;
			while (tmp != NULL) {
				cout << tmp->key;
				if (tmp->next != NULL) cout << ", ";
				tmp = tmp->next;
			}
			cout << endl;
		}

		singleNode* search(int searchKey){
			singleNode* tmp = head;
			singleNode* returnNode = NULL;
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

		void insertHead(singleNode* newNode){
			newNode->next = head;
			head = newNode;
		}
/* This is covered by insertNode, depracated
		void insertTail(singleNode* newNode){
			singleNode* tmp = head;
			while (tmp->next != NULL) {
				tmp = tmp->next;
			}
			tmp->next = newNode;
		}
*/
		void insertNode(int* prevValue, singleNode* newNode) {
			// Insert at head
			if (prevValue == NULL) {
				newNode->next = head;
				head = newNode;
			// Insert at middle or tail
			} else { 
				singleNode* tmp = head;
				while (tmp->key != *prevValue && tmp != NULL) {
					tmp = tmp->next;
				}
				newNode->next = tmp->next;
				tmp->next = newNode;
			}
		}

		--
		Node* Insert(Node *head,int data)
{
  // creating a temprary which holds the last node and  it also set last node data and next
    node *end = new  node;
    end->data = data;
    end->next = NULL;
    // if the linked_list is empty then set head = last
    if (head == NULL)
     {
        head = end;
    } 
    else
     { // if the linked list is not empty
        // creating a temprary node and sets it to head
         node *temp = new  node;
        temp = head;
        // using temp to find the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // appending the last node with last
        temp->next = end;
    }
    // returning the head of linked list
    return head;
}




		--
		
		void deleteNode(int searchKey) {
			// If head contains searchKey
			singleNode* tmp;
			if (head->key == searchKey) {	
				tmp = head;
				head = head->next;
				tmp->next = NULL;
			// Else it's in the middle
			} else {
				singleNode* left = head;
				singleNode* deleting = left->next;
				while ((deleting->next != NULL) && (deleting->key != searchKey)) {
					left = left->next;
					deleting = deleting->next;
				}
				if (deleting->key == searchKey) {
					tmp = left->next;
					left->next = deleting->next;
					tmp->next = NULL;
					
				}
			}
		}
};

int main() {
	singleNode head;
	head.key = 5;
	head.next = NULL;

	singleNode a;
	a.key = 6;
	a.next = NULL;
	//head.next = &a;

	singleNode b;
	b.key = 7;
	b.next = NULL;
	head.next = &b;

	cout << "head: " << head.key << endl;
	cout << "head next: " << head.next << endl;
	cout << "next key: " << head.next->key << endl;
	
	SinglyLinkedList list(&head);
	list.traverse();

	// Test search
	singleNode* res = list.search(6);
	if (res != NULL) { 
		cout << "Search returned: " << res->key << endl;
	} else {
		cout << "Search returned: " << res << endl;
	}

	// Test insertHead
	singleNode c;
	c.key = 4;
	c.next = NULL;

	list.insertHead(&c);
	list.traverse();

	// Test insertNode
	int val = 5;
	int* prevValue = NULL;
	list.insertNode(prevValue, &a);
	list.traverse();

	// Test deleting
	list.deleteNode(10);
	list.traverse();

	return 0;
}


int LinkedListNthNode(node *head, int position);
singleNode* tmp = head;
for(int i=0; i<position;i++)
{
	if (tmp->next != NULL) 
	{
		if(tmp==value)
		{
		 return position
		}
    }
	if(tmp!=value)
	{
	return -1;
    }
}