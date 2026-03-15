/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        queue<pair<Node*, int>> q;
        q.push({root,0});
        map<int, vector<int>> mp;
        
        while(!q.empty()) {
           auto it = q.front();
           q.pop();
           Node* node = it.first;
           int ht = it.second;
           mp[ht].push_back(node->data);
           
           if(node->left)  q.push({node->left , ht-1});
           if(node->right) q.push({node->right, ht+1});
        }
        
        vector<vector<int>>ans;
        for(auto it: mp) ans.push_back(it.second);
        
        return ans;
    }
};
