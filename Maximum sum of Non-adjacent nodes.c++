class Solution {
  public:
    int solve(unordered_map<Node*, int> &dp, Node *root) {
        if(root == NULL) return 0;
        
        if(dp[root]) return dp[root];
        
        int take = root->data;
        
        if(root->left) {
            take += solve(dp, root->left->left);
            take += solve(dp, root->left->right);
        }
        
        if(root->right) {
            take += solve(dp, root->right->left);
            take += solve(dp, root->right->right);
        }
        
        int non_take = solve(dp, root->left) + solve(dp, root->right);
        
        return dp[root] = max(take, non_take);
    }
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        // code here
        unordered_map<Node*, int> dp;
        return solve(dp, root);
    }
};
