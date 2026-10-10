//Lowest common accestor
#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
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

    Node *newnode = new Node(nodes[idx]);
    newnode->left = buildTree(nodes);
    newnode->right = buildTree(nodes);

    return newnode;
}

bool root_to_node(Node* root, int n, vector<int> &path) {
    if(root == NULL) {
        return false;
    }
    path.push_back(root->data);
    if(root->data == n) {
        return true;
    }
    bool isfind = root_to_node(root->left, n, path) || root_to_node(root->right, n, path);
    if(!isfind) {
        path.pop_back();
    }
    return isfind;

}

int LCA(Node* root, int n1, int n2) {
    vector<int> path1, path2;

    root_to_node(root, n1, path1);
    root_to_node(root, n2, path2);

    int lca = -1;
    for(int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++) {
        if(path1[i] != path2[j]) {  
            return lca;
        }
        lca = path1[i];
    }

}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, 7, -1, -1};
    Node* root = buildTree(nodes);

    cout << LCA(root, 3, 5);
    return 0;
}