/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(vector<int>&ans,Node*root){
        if(root==NULL){
            return;
        }
        
        solve(ans,root->left);
        solve(ans,root->right);
        ans.push_back(root->data);
    }
    
    vector<int> postOrder(Node* root) {
        vector<int>ans;
        solve(ans,root);
        return ans;
    }
};
