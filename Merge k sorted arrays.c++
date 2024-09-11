class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> result;
        
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                result.push_back(arr[i][j]);
            }
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};
