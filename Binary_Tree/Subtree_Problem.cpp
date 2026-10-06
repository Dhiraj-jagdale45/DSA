// subtree is another tree

#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(vector<int> nodes) {
    static int idx = -1;
    idx++;
    if(nodes[idx] == -1) {
        return NULL;
    }

    Node* newnode = new Node(nodes[idx]);
    newnode->left = buildTree(nodes);
    newnode->right = buildTree(nodes);

    return newnode;
}
bool isIdentical(Node* node1, Node* node2) {
    if(node1 == NULL && node2 == NULL) {
        return true;
    }

    if(node1 == NULL || node2 == NULL) {
        return false;
    }

    if(node1->data != node2->data) {
        return false;
    }

    bool is_left = isIdentical(node1->left, node2->left);
    bool is_right = isIdentical(node1->right, node2->right);

    return(is_left && is_right);
}

bool isSubroot(Node* root, Node* subroot) {
    if(root == NULL && subroot == NULL) {
        return true;
    }
    if(root == NULL || subroot == NULL) {
        return false;
    }

    if(root->data == subroot->data) {
        if(isIdentical(root, subroot)) {
            return true;
        }
    }

    bool is_find_left = isSubroot(root->left, subroot);
    if(!is_find_left) {
        return isSubroot(root->right, subroot);
    }
    return is_find_left;
}


int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);
    Node *subRoot = new Node(6);
    subRoot->left = new Node(4);
    subRoot->right = new Node(6);

    cout << isSubroot(root, subRoot);
    return 0;
}
