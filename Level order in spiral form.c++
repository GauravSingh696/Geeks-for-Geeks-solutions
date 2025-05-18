/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        vector<int> res;
        res.push_back(root->data);
        
        deque<Node*> q;
        q.push_back(root);
        
        int level=0;
        
        while(!q.empty()){
            int n=q.size();
            
            if(level%2==0){
                while(n--){
                    Node* node=q.front();
                    q.pop_front();
                    
                    if(node->left){
                        q.push_back(node->left);
                        res.push_back(node->left->data);
                    }
                    
                    if(node->right){
                        q.push_back(node->right);
                        res.push_back(node->right->data);
                    }
                }
            }
            
            else{
                while(n--){
                    Node* node=q.back();
                    q.pop_back();
                    
                    if(node->right){
                        q.push_front(node->right);
                        res.push_back(node->right->data);
                    }
                     
                    if(node->left){
                        q.push_front(node->left);
                        res.push_back(node->left->data);
                    }
                }
            }
            
            level++;
        }
        
        return res;
    }
};
