/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

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
  
    vector<Node*> findPreSuc(Node* root, int key) {
        inorder(root);
        Node *pre = NULL, *sec = NULL;
        
        for(int i=0;i<vec.size();i++) {
            if(vec[i]->data == key) {
                if(i>0)
                    pre = vec[i-1];
                
                if(i<vec.size()-1)
                    sec = vec[i+1];
                
                break;
            }
            
            else if(vec[i]->data > key) {
                if(i>0) 
                    pre = vec[i-1];
                
                sec = vec[i];
                
                break;
            }
        }
        
        if(!pre && !sec) {
            pre = vec[vec.size()-1];
        }
        
        return {pre, sec};
    }
};
