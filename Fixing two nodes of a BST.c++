/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> vec;
    
    void inorder(Node* root) {
        if(root) {
            inorder(root->left);
            vec.push_back(root);
            inorder(root->right);
        }
    }
    
    void correctBST(Node* root) {
        inorder(root);
        
        int n = vec.size();
        int i = 0;
        
        while(i<n-1) {
            if(vec[i]->data > vec[i+1]->data)
                break;
            i++;
        }
        
        int j = n-1;
        
        while(j>0) {
            if(vec[j]->data < vec[j-1]->data)
                break;
            j--;
        }
        
        swap(vec[i]->data , vec[j]->data);
    }
};
