class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> a, int n){
        // code here
        
        int buy;
        vector<vector<int>> result;
        
        for(int i=1;i<n;i++)
        {
            if(a[i] > a[i-1])
            {
                result.push_back({i-1 , i});
            }
        }
        
        return result;
    }
};
