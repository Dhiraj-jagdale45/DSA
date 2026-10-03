
#include <iostream>
#include <vector>
#include<queue>
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

Node *buildTree(vector<int> nodes) { // Time complexity:- O(n) 
    static int idx = -1;
    idx++;

    if (nodes[idx] == -1) {
        return NULL;
    }

    Node *newnode = new Node(nodes[idx]);
    newnode->left = buildTree(nodes); // left subtree
    newnode->right = buildTree(nodes); // right subtree

    return newnode;
}

void preorder(Node *root) { // O(n)
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) { //O(n)
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root) { //O(n)
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void level_traversal(Node *root) { // time complexity:- O(n) space complexity:- O(n)
    if(root == NULL) {
        return ;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();
        if(front == NULL && !q.empty()) {
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << front->data << " ";
        if(front->left != NULL) q.push(front->left);
        if(front->right != NULL) q.push(front->right);
    }
}

int height_tree(Node* root) { // O(n)
    if(root == NULL) return 0;
    
    int lh = height_tree(root->left);
    int rh = height_tree(root->right);

    return 1 + max(lh, rh);
}

int count_nodes(Node* root) { //O(n)
    static int count = 0;
    if(root == NULL) {
        return 0;
    }
    count++;
    count_nodes(root->left);
    count_nodes(root->right);

    return count;
}

int total_sum(Node* root) { //O(n)
    static int sum = 0;
    if(root == NULL) {
        return 0;
    }
    sum += root->data;
    total_sum(root->left);
    total_sum(root->right);

    return sum;

}

void sum_of_nodes_of_same_level(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int sum = 0;

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();
        if(!q.empty() && front == NULL) {
            cout << sum << endl;
            sum = 0;
            q.push(NULL);
            // continue;
        }
        else {
            if(front != NULL) {
                sum += front->data;
                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);
            }
        }

    }
    cout << sum;
    return;

}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1}; //-1 represent the null value
    Node *root = buildTree(nodes);
    cout << "root = " << root->data;
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    level_traversal(root);

    cout << "height of tree is :- " << height_tree(root);
    cout << "No. of nodes in tree :-" << count_nodes(root);
    cout << "Total sum  of nodes is :- " << total_sum(root);
    sum_of_nodes_of_same_level(root);
    return 0;
}