// 02-05-2024

class Solution
{
    public:
    
    void preorder(Node *root, vector<int> &result)
    {
        if(root==NULL)
        {
            result.push_back(-1);
            return ;
        }
        
        result.push_back(root->data);
        
        preorder(root->left, result);
        preorder(root->right, result);
    }
    
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> result;
        preorder(root, result);
        return result;
    }
    
    Node *solve(int &idx, vector<int> &A)
    {
        if(idx==A.size() || A[idx]==-1)
        {
            idx++;
            return NULL;
        }
        
        Node *root = new Node(A[idx]);
        idx++;
        
        root->left = solve(idx, A);
        root->right = solve(idx, A);
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       
       int idx=0;
       return solve(idx, A);
    }

};
