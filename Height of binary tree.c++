/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        if(!node)
            return -1;
        
        int left = 0, right = 0;
        
        if(node->left)
            left = 1 + height(node->left);
        
        if(node->right) 
            right = 1 + height(node->right);
        
        return max(left, right);
    }
};
