//kth level
#include<iostream>
#include<queue>
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

// void kth_level_nodes(Node* root, int k) { // iterative approach
 
//     if(root == NULL || k == 0) {
//         cout << "Please enter valid input!!";
//         return;
//     }
//     queue<Node*> q;
//     int level = 1;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty()) {
//         Node* front = q.front();
//         if(level == k) {
//             while(!q.empty()) {
//                 if(q.front() == NULL) {
//                     q.pop();
//                 }else {
//                     cout << q.front()->data << endl;
//                     q.pop();
//                 }
//             }
//             break;
//         }
//         q.pop();
//         if(front == NULL && !q.empty()) {
//             q.push(NULL);
//             level++;
//             continue;
//         }
//         if(front->left != NULL) q.push(front->left);
//         if(front->right != NULL) q.push(front->right);
//     }
// }   


void kth_helper(Node* root, int k, int currlevel) { //kth_helper 

    if(root == NULL) {
        return;
    }
    if(currlevel == k) {
        cout << root->data << " ";
        return;
    }

    kth_helper(root->left ,k, currlevel + 1);
    kth_helper(root->right, k, currlevel + 1);
}

void kth_level_nodes(Node* root, int k) { // recersive approach
    if(root == NULL || k == 0) {
        return;
    }

    kth_helper(root, k, 1);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, 7, -1, -1};

    Node* root = buildTree(nodes);

    kth_level_nodes(root, 4);
    return 0;
}