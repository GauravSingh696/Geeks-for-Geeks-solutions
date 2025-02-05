/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(!node)
            return ;
        
        swap(node->left, node->right);
        
        mirror(node->right);
        mirror(node->left);
    }
};
