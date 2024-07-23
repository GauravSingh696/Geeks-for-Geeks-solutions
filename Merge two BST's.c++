// 23-07-2024

class Solution {
  public:
    void inorder(Node *root, vector<int> &vec)
    {
        if(root)
        {
            inorder(root->left , vec);
            vec.push_back(root->data);
            inorder(root->right , vec);
        }
    }
  
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> result;
        
        inorder(root1 , result);
        inorder(root2 , result);
        
        sort(result.begin() , result.end());
        
        return result;
        
    }
};
