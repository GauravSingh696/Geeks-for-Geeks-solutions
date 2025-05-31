class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        unordered_map<int,int>mp1,mp2;
        int n = mat1.size();
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                mp1[mat1[i][j]]++;
                mp2[mat2[i][j]]++;
            }
        }
        
        int count=0;
        
        for(auto it=mp1.begin();it!=mp1.end();it++) {
            if(mp2[x-it->first] > 0)
                count++;
        }
        
        return count;
    }
};
