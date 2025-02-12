/*
Node is as follows
class Node {
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
   unordered_set<int> st;
    
    void inorder(Node *root) {
        if(!root) return;
        
        inorder(root->left);
        st.insert(root->data);
        inorder(root->right);
    }

    bool findTarget(Node *root, int target) {
        // your code here.
        inorder(root);
        if(st.size()<2) return 0;
        
        for(int it:st ){
            if(st.find(target-it)!=st.end())
                return true;
        }
        
        return false;
    }
};
