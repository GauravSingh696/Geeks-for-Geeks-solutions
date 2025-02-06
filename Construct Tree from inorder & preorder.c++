/*
Definition of the Node class
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
};
*/
class Solution {
  public:
    Node *solve(vector<int> &inorder, vector<int> &preorder, int start, int end, int &idx) {
        if(start > end)
            return NULL;
        
        int root_val = preorder[idx];
        idx++;
        
        int i = start;
        
        for(; i<=end ; i++) {
            if(inorder[i] == root_val)
                break;
        }
        
        Node *root = new Node(root_val);
        
        root->left  = solve(inorder, preorder, start, i-1, idx);
        root->right = solve(inorder, preorder, i+1, end, idx);
        
        return root;
    }
  
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = preorder.size();
        
        int idx = 0;
        
        return solve(inorder, preorder, 0, n-1, idx);
    }
};
