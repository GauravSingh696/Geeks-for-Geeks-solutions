// 02-06-2024

class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        vector<int> result;
        int sum=0;
        int n=queries.size();
        for(int i=n-1 ; i>=0 ; i--)
        {
            if(queries[i][0]==0)
            {
                result.push_back(queries[i][1]^sum);
            }
            
            else
            {
                sum^=queries[i][1];
            }
        }
        result.push_back(sum);
        sort(result.begin() , result.end());
        return result;
    }
};
