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
    void solve(Node* root, int l, int sum, int &h, int &result) {
        if(!root)
            return ;
        
        sum += root->data;
        
        if(!root->left && !root->right) {
            if(l > h)
                result = sum;
            
            else if(l == h)
                result = max(sum, result);
        }
        
        h = max(h, l);
        
        solve(root->left , l+1, sum, h, result);
        solve(root->right, l+1, sum, h, result);
    }
  
    int sumOfLongRootToLeafPath(Node *root) {
        int result = 0;
        int h = -1;
        
        solve(root, 0, 0, h, result);
        
        return result;
    }
};
