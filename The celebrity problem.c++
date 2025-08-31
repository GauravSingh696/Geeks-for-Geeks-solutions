class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        unordered_map<int, vector<int>> mp;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == 1) {
                    mp[i].push_back(j);
                }
            }
        }
        
        int Celebrity = -1;
        
        for(auto it : mp) {
            if(it.second.size() == 1) {
                if(it.second[0] == it.first) {
                    Celebrity = it.first;
                    break;
                }
            }
        }
        
        for(auto it : mp) {
            bool flag = true;
            
            for(auto i : it.second) {
                if(i == Celebrity) {
                    flag = false;
                    break;
                }
            }
            
            if(flag)
                return -1;
        }
        
        return Celebrity;
    }
};
