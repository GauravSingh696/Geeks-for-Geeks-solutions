/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        queue<Node*> que;
        que.push(root);
        
        vector<vector<int>> result;
        result = {{root->data}};
        
        while(!que.empty()) {
            int n = que.size();
            vector<int> vec;
            
            while(n--) {
                Node* temp = que.front();
                
                if(temp->left) {
                    vec.push_back(temp->left->data);
                    que.push(temp->left);
                }
                
                if(temp->right) {
                    vec.push_back(temp->right->data);
                    que.push(temp->right);
                }
                
                que.pop();
            }
            
            result.push_back(vec);
        }
        
        return result;
    }
};
