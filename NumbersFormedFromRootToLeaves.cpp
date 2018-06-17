#include <iostream>

using namespace std;

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* makeNode(int val) {
    struct Node* root = new Node();
    root->val = val;
    root->left = nullptr;
    root->right = nullptr;
    return root;
}

int sum(Node* root, int val) {
    if(root == nullptr) return 0;
    val = val*10 + root->val;
    if(root->left == nullptr && root->right == nullptr) {
        return val;
    }
    else {
        return sum(root->left, val) + sum(root->right, val);
    }

}

int sumUtil(Node* root) {
    return sum(root, 0);
}

int main() {
    Node* node = makeNode(6);
    node->left = makeNode(3);
    node->right = makeNode(5);
    node->left->left = makeNode(2);
    node->left->right = makeNode(5);
    node->left->right->left = makeNode(7);
    node->left->right->right = makeNode(4);
    node->right->right = makeNode(4);
    cout << "result is " << sumUtil(node) << endl;
    return 0;
}
