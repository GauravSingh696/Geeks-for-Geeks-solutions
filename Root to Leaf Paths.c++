// 08-05-2024

class Solution {
  public:
    void solve(Node *root, vector<int> curr, vector<vector<int>> &result)
    {
        if(root==NULL)
        {
            return ;
        }
        
        curr.push_back(root->data);
        
        if(root->left==NULL && root->right==NULL)
        {
            result.push_back(curr);
            return ;
        }
        
        solve(root->left, curr, result);
        solve(root->right, curr, result);
        
        return;
    }
  
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> result;
        vector<int> curr;
        
        solve(root, curr, result);
        
        return result;
    }
};
