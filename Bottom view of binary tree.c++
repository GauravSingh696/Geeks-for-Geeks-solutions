/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* node, int x, int y, map<int, pair<int, int>>&mp){
        if(!node) return;
        if(mp.find(y)==mp.end()){
            mp[y]={x, node->data};
        }else{
            if(mp[y].first<=x){
                mp[y]={x, node->data};
            }
        }
        solve(node->left, x+1, y-1, mp);
        solve(node->right, x+1, y+1, mp);
    }
  
    vector<int> bottomView(Node *root) {
        map<int, pair<int, int>> mp;
        vector<int>ans;
        
        solve(root, 0, 0, mp);
        
        for(auto &it:mp) {
            ans.push_back(it.second.second);
        }
        
        return ans;
    }
};


