/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return maximum path sum from any node in a tree.
    pair<int, int> solve(Node *root) {
        if(!root)
            return {INT_MIN , 0};
        
        pair<int, int> left_sum  = solve(root->left);
        pair<int, int> right_sum = solve(root->right);
        
        int curr_sum = max(root->data , root->data + max(left_sum.second , right_sum.second));
        
        int gol_max = max({left_sum.first , right_sum.first , curr_sum , root->data + left_sum.second + right_sum.second});
        
        return {gol_max , curr_sum};
    }
    
    int findMaxSum(Node *root) {
        return max(solve(root).first , solve(root).second);
    }
};
