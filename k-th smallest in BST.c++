/*Complete the function below

struct Node {
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
    // Return the Kth smallest element in the given BST
    vector<int> v;
    
    void inorder(Node *root) {
        if(!root) return;
        
        inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
    }
    int kthSmallest(Node *root, int k) {
        inorder(root);
        
        return k>v.size()?-1:v[k-1];
    }
};
