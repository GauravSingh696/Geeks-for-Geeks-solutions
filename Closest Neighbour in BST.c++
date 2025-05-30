/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int CNBST(Node* root, int &k){
        if(!root){
            return -1;
        }
        if(root->data > k){
            return CNBST(root->left,k);
        }
        
        return max(root->data, CNBST(root->right,k));
    }
    
    int findMaxFork(Node* root, int k) {
        return CNBST(root,k);
    }
};
