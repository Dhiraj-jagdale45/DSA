//Top view of tree
#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        right = NULL;
        left = NULL;
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

static map<int, int> m;
void horizontal_distance(Node* root, int x) {
    if(root == NULL) {
        return ;
    }
    if(m.count(x) != 1) {
        m[x] = root->data;
    }
    horizontal_distance(root->left, x-1);
    horizontal_distance(root->right, x+1);

    
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    Node* root = buildTree(nodes);

    horizontal_distance(root, 0);

    for(auto it : m) {
        cout << it.second << "    ";
    }
    return 0;
}
