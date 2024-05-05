// 05-05-2024

class Solution{
    map<int, int> mp;
    
    public:
        void solve(Node *root, int dist)
        {
            mp[dist] += root->data;
        
            if(root->left)
                solve(root->left, dist-1);
        
            if(root->right)
                solve(root->right, dist+1);
        }
  
        vector <int> verticalSum(Node *root) {
        
            solve(root, 0);
        
            vector<int> result;
        
            for(auto it : mp)
            {
                result.push_back(it.second);
            }
        
            return result;
        }
};
