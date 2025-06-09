/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool result;
    
    void solve(Node* curr, int mn, int mx) {
        if(!curr || result)
            return ;
        
        if(!curr->left && !curr->right) {
            if(mn == mx)
                result = true;
            
            return ;
        }
        
        solve(curr->left, mn, curr->data-1);
        solve(curr->right, curr->data+1, mx);
    }
  
    bool isDeadEnd(Node *root) {
        result = false;
        
        solve(root, 1, 1e5);
        
        return result;
    }
};
