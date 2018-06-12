#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	int key;
	struct Node* left;
	struct Node* right;
	int height;
};

struct Node* NewNode(int key) {
	struct Node* node = new Node();
	node->key = key;
	node->left = nullptr;
	node->right = nullptr;
	node->height = 0;
	return node;
}

int GetHeight(struct Node* root) {
	if(root == nullptr) return -1;
	return root->height;
}

struct Node* RightRotate(struct Node* root) {
	struct Node* leftChild = root->left;
	struct Node* rightChild = leftChild->right;
	root->left = rightChild;
	leftChild->right = root;
	// root->left = rightChild;
	root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	leftChild->height = max(GetHeight(leftChild->left), GetHeight(leftChild->right)) + 1;
	return leftChild;
}

struct Node* LeftRotate(struct Node* root) {
	struct Node* rightChild = root->right;
	struct Node* leftChild = rightChild->left;
	root->right = leftChild;
	rightChild->left = root;
	// root->right = leftChild;
	root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	rightChild->height = max(GetHeight(rightChild->left), GetHeight(rightChild->right)) + 1;
	return rightChild;
}

int GetBalance(struct Node* root) {
	if(root == nullptr) return 0;
	return GetHeight(root->left) - GetHeight(root->right);
}

struct Node* insert(struct Node* node, int key) {
	if(node == nullptr) return NewNode(key);
	if(key < node->key) node->left = insert(node->left, key);
	else if(key > node->key) node->right = insert(node->right, key);
	else return node;
	
	node->height = max(GetHeight(node->left), GetHeight(node->right)) + 1;

	int balance = GetBalance(node);

	if(balance > 1 && key < node->left->key) {
		return RightRotate(node);
	}
	if(balance > 1 && key > node->left->key) {
		node->left = LeftRotate(node->left);
		return RightRotate(node);
	}
	if(balance < -1 && key < node->right->key) {
		node->right = RightRotate(node->right);
		return LeftRotate(node);
	}
	if(balance < -1 && key > node->right->key) {
		return LeftRotate(node);
	}
	return node;
}

void Print(struct Node* root) {
	if(root != nullptr) {
		cout << root->key << " " << endl;
		Print(root->left);
		Print(root->right);
	}
}

int main() {
	struct Node* root = nullptr;

	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	cout << "Preorder traversal of AVL tree is " << endl;
	Print(root);
	return 0;
}
