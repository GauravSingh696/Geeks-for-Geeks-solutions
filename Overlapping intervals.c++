class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& inter) {
        vector<vector<int>> result;
        sort(inter.begin() , inter.end());
        int n = inter.size();
        int i=0 , j=1;
        
        while(j<n)
        {
            if(inter[j][0] > inter[j-1][1])
            {
                result.push_back({inter[i][0] , inter[j-1][1]});
                i=j;    j++;
            }
            
            else
            {
                inter[j][1] = max(inter[j][1] , inter[j-1][1]);
                j++;
            }
        }
        
        result.push_back({inter[i][0] , inter[j-1][1]});
        
        return result;
    }
};
