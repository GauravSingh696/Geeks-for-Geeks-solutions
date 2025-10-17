/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, vector<int>& inorder){
        if(root) {
            solve(root->left, inorder);
            inorder.push_back(root->data);
            solve(root->right, inorder);
        }
    }
  
    int findMedian(Node* root) {
        vector<int> inorder;

        solve(root, inorder);
    
        int n= inorder.size();
        
        if (n % 2 != 0) {
            return inorder[(n+1) / 2 - 1];
        } else {
            return inorder[n / 2 - 1];  
        }
    }
};
