#include <iostream>

using namespace std;

struct node{
	int key;
	node* parent;
	node* leftChild;
	node* rightChild;
};

class BinarySearchTree{
	private:
		node* root;
		node* searchRecursive(node* n, int value) {
			return NULL;
		}

		void printNode(node* n) {
			if (n == NULL) {
				return;
			}
			if (n->leftChild != NULL) { // Print everything to the left (lesser than our key)
				printNode(n->leftChild);
			}
			cout << n->key << " "; // print the key
			if (n->rightChild != NULL) { // Print everything to the right (greater than our key)
				printNode(n->rightChild);
			}
		}

		node* treeMinimum(node* n) {
			if (n->leftChild != NULL ) { // go left!
				return treeMinimum(n->leftChild);
			}
			return n;
		}

		void deleteTreePrivate(node* n) {
			if (n == NULL) {
				return;
			}
			if (n->leftChild != NULL) { // Print everything to the left (lesser than our key)
				deleteTreePrivate(n->leftChild);
			}
			if (n->rightChild != NULL) { // Print everything to the right (greater than our key)
				deleteTreePrivate(n->rightChild);
			}
			if (n == root) {
				root = NULL;
			}
			delete n;
		}

	public:
		BinarySearchTree() {
			root = NULL;
		}
		~BinarySearchTree() {
			//delete root; 
			cout << "\ndestructing!\n";
			deleteTree();
		}

		int insertNode(int value) {
			// Initialize new node
			node* newNode = new node;
			newNode->key = value;
			newNode->parent = NULL;
			newNode->rightChild = NULL;
			newNode->leftChild = NULL;

			//
			node* tmp = root;
			node* parent = tmp;
			while (tmp != NULL) { // find the parent node
				parent = tmp;
				if (value < tmp->key) { // move left
					tmp = tmp->leftChild;
				} else if (value > tmp->key) { // move right
					tmp = tmp->rightChild;
				} else { // already here
					return -1;
				}
			}
			if (parent == NULL) { // inserting at the root
				root = newNode;
			} else if (value < parent->key) { // left child
				parent->leftChild = newNode;
			} else if (value > parent->key) { // right child
				parent->rightChild = newNode;
			}
			newNode->parent = parent;
			return 0;
		}

		void printHelper() {
			printNode(root);
		}

		int deleteNode(int value) {
			node* tmp = root;

			while (tmp != NULL) {
				if (value == tmp->key) { // found the node for delete

					// Perform delete, one of three cases
					if (tmp->leftChild == tmp->rightChild) { // no children
						if (tmp->parent != NULL) { // not the root
							if (value < tmp->parent->key) {
								tmp->parent->leftChild = NULL;
							} else {
								tmp->parent->rightChild = NULL;
							}
							delete tmp;
							return 0;
						}
					} else if ((tmp->leftChild != NULL) != (tmp->rightChild != NULL)) { // one child
						
						if (tmp->parent != NULL) { // not the root
							if (value < tmp->parent->key) { // we are left of the parent
								if (tmp->leftChild != NULL) { // which child do we have?
									tmp->parent->leftChild = tmp->leftChild;
									tmp->leftChild->parent = tmp->parent;
								} else {
									tmp->parent->leftChild = tmp->rightChild;
									tmp->rightChild->parent = tmp->parent;
								}
							} else { // we are right of the parent
								if (tmp->leftChild != NULL) { // which child do we have?
									tmp->parent->rightChild = tmp->leftChild;
									tmp->leftChild->parent = tmp->parent;
								} else {
									tmp->parent->rightChild = tmp->rightChild;
									tmp->rightChild->parent = tmp->parent;
								}
							}
						}
						delete tmp;
						return 0;

					} else { // two children
						node* rightMin = treeMinimum(tmp->rightChild); 
						if (tmp->parent != NULL) {  // not the root

							// update right child pointer 
							if (rightMin->key != tmp->rightChild->key) {
								rightMin->rightChild = tmp->rightChild;
								tmp->rightChild->parent = rightMin;
								rightMin->parent->leftChild = NULL;
							}
							
							// update parent pointers
							rightMin->parent = tmp->parent;
							if (value < tmp->parent->key) { // we are left of parent
								tmp->parent->leftChild = rightMin;
							} else { // to the right of parent
								tmp->parent->rightChild = rightMin;
							}

							// update left child pointer (referring to the tmp)
							if (tmp->leftChild != NULL) {
								rightMin->leftChild = tmp->leftChild;
								tmp->leftChild->parent = rightMin;
							}

						}
						delete tmp;
						return 0;
					}

				} else { // keep looking
					if (value < tmp->key) tmp = tmp->leftChild;
					else tmp = tmp->rightChild;
				}
			}
			return 0;
		}

		void deleteTree() {
			deleteTreePrivate(root);
			return;
		}
};

int main() {
	BinarySearchTree bst;

	// Test insert
	bst.insertNode(5);
	bst.insertNode(6);
	bst.insertNode(2);
	bst.insertNode(4);
	bst.insertNode(3);
	bst.insertNode(9);
	bst.insertNode(1);

	// Test delete 
	cout << "Before delete: ";
	bst.printHelper();
	bst.deleteNode(2);
	//bst.deleteTree();

	// Output in order
	cout << "\nAfter delete:  ";
	bst.printHelper();

	return 0;
}