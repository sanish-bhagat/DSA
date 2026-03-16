#include<bits/stdc++.h>
using namespace std;

class Node {
  public :
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int countRec(Node *node, int k, int sum, unordered_map<int, int> &prefSums) {

    if(!node)
        return 0;

    int pathCount = 0;

    sum += node -> data;

    if(sum == k)
        pathCount++;

    pathCount += prefSums[sum - k];

    prefSums[sum]++;

    pathCount += countRec(node -> left, k, sum, prefSums);
    pathCount += countRec(node -> right, k, sum, prefSums);

    prefSums[sum]--;

    return pathCount;
}

int countAllPaths(Node *root, int k) {
    unordered_map<int, int> prefSums;

    return countRec(root, k, 0, prefSums);
}

int main() {
  
    // Create a sample tree:
    //        8
    //      /  \
    //     4    5
    //    / \    \
    //   3   2    2
	//  / \   \
    // 3  -2   1

    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(2);
  	root->left->left->left = new Node(3);
  	root->left->left->right = new Node(-2);
    root->left->right->right = new Node(1);

    int k = 7; 

    cout << countAllPaths(root, k) << endl;
    return 0;
}