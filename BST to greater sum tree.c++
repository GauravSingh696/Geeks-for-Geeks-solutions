/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    int cs = 0;
    
    void transformTree(Node *root) {
        if(!root)
            return ;
        
        int val = root->data;
        
        transformTree(root->right);
        
        root->data = cs;
        
        cs += val;
        
        transformTree(root->left);
    }
};
