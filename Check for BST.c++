// 24-07-2024

class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    void inorder(Node *root, vector<int> &vec)
    {
        if(root)
        {
            inorder(root->left, vec);
            vec.push_back(root->data);
            inorder(root->right, vec);
        }
    }
    
    bool isBST(Node* root) {
        // Your code here
        
        if(!root)
            return true;
        
        vector<int> vec;
        
        inorder(root , vec);
        
        for(int i=0;i<vec.size()-1;i++)
        {
            if(vec[i] == vec[i+1])
                return false;
        }
        
        if(is_sorted(vec.begin(), vec.end()))
            return true;
        
        return false;
        
    }
};
