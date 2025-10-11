/*
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
    int solve(Node* root, int &sum) {
        if(root == NULL) 
            return 0;
        
        int left  = max(0, solve(root->left , sum));
        int right = max(0, solve(root->right, sum));
        
        int curr_sum = root->data + left + right;
        
        sum = max(sum , curr_sum);
        
        return root->data + max(left, right);
    }
  
    int findMaxSum(Node *root) {
        int sum = INT_MIN;
        
        solve(root, sum);
        
        return sum;
    }
};
