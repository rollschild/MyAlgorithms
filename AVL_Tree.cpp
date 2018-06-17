#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int key;
	struct Node* left;
	struct Node* right;
	int height;
};

int getHeight(struct Node* root) {
	if(root == nullptr) return -1;
	return root->height;
}

struct Node* newNode(int key) {
	struct Node* node = new Node();
	node->key = key;
	node->left = nullptr;
	node->right = nullptr;
	node->height = 0;
	return node;
}

struct Node* leftRotate(struct Node* root) {
	struct Node* rc = root->right;
	struct Node* rlc = rc->left;
	root->right = rlc;
	rc->left = root;
	rc->height = max(getHeight(rc->left), getHeight(rc->right)) + 1;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	return rc;
}

struct Node* rightRotate(struct Node* root) {
	struct Node* lc = root->left;
	struct Node* lrc = lc->right;
	root->left = lrc;
	lc->right = root;
	lc->height = max(getHeight(lc->left), getHeight(lc->right)) + 1;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	return lc;
}

int getBalance(struct Node* root) {
	if(root == nullptr) return 0;
	return getHeight(root->left) - getHeight(root->right);
}

struct Node* getMin(struct Node* root) {
	struct Node* node = root;
	while(node->left != nullptr) {
		node = node->left;	
	}
	return node;
}

struct Node* insert(struct Node* root, int key) {
	if(root == nullptr) return newNode(key);
	if(key < root->key) root->left = insert(root->left, key);
	else if (key > root->key) root->right = insert(root->right, key);
	else return root;
	
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

	int balance = getBalance(root);
	if(balance > 1 && key < root->left->key) {
		return rightRotate(root);	
	}
	if(balance < -1 && key > root->right->key) {
		return leftRotate(root);	
	}
	if(balance > 1 && key > root->left->key) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance < -1 && key < root->right->key) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	/*
	if(balance < -1 && key > root->right->key) {
		return leftRotate(root);	
	}
	*/
	return root;
}

struct Node* remove(struct Node* root, int key) {
	if(root == nullptr) return root;
	if(key < root->key) {
		root->left = remove(root->left, key);
	}
	else if(key > root->key) {
		root->right = remove(root->right, key);	
	}
	else {
		// remove this current root!
		if(root->left == nullptr || root->right == nullptr) {
			struct Node* temp = root->left ? root->left : root->right;
			if(temp == nullptr) {
				temp = root;
				root = nullptr;
			}
			else {
				*root = *temp; // this is new to me!!!
			}
			delete temp;
		}
		else {
			struct Node* successor = getMin(root->right);
			root->key = successor->key;
			root->right = remove(root->right, successor->key);
		}
	}
	
	if(root == nullptr) return root;
	
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	int balance = getBalance(root);

	if(balance > 1 && getBalance(root->left) >= 0) {
		return rightRotate(root);
	}
	if(balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance < -1 && getBalance(root->right) <= 0) {
		return leftRotate(root);	
	}
	if(balance < -1 && getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

void print(struct Node* root) {
	if(root != nullptr) {
		cout << root->key << " ";
		print(root->left);
		print(root->right);
	}
}

int main() {
	struct Node* root = nullptr;
	/*
	root = insert(root, 9);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 0);
	root = insert(root, 6);
	root = insert(root, 11);
	root = insert(root, -1);
	root = insert(root, 1);
	root = insert(root, 2);
	*/
	
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 60);
	root = insert(root, 70);
	root = insert(root, 80);
	root = insert(root, 90);
	root = insert(root, 99);
	
	cout << "original tree is " << endl;
	
	print(root);
	cout << endl;
	root = remove(root, 60);
	
	cout << "new tree is " << endl;
	print(root);
	cout << endl;
	return 0;
}
