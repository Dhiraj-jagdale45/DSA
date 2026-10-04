//Diameter of tree

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

int diameter_of_node(Node* node) { // O(n)
    if(node == NULL) {
        return 0;
    }

    int lh = diameter_of_node(node->left); 
    int rh = diameter_of_node(node->right); 

    return (1 + max(lh, rh));
}

int diameter_of_tree(Node *root) { //O(n^2)
    if(root == NULL) {
        return 0;
    }
    static int diameter = 0;
    diameter = max((diameter_of_node(root->left) + diameter_of_node(root->right) + 1), diameter);
    diameter_of_tree(root->left);
    diameter_of_tree(root->right);

    return diameter;
}


int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << diameter_of_tree(root);
    return 0;
}