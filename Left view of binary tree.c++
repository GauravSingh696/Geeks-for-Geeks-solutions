class Solution {
  public:
    vector<int> leftView(Node *root) {
        if(!root)
            return {};
        
        vector<int> result;
        queue<Node*> que;
        que.push(root);
        
        while(!que.empty()) {
            int n = que.size();
            
            for(int i=0;i<n;i++) {
                Node* node = que.front();
                que.pop();
                
                if(i==0) {
                    result.push_back(node->data);
                }
                
                if(node->left)
                    que.push(node->left);
                
                if(node->right)
                    que.push(node->right);
            }
        }
        
        return result;
    }
};
