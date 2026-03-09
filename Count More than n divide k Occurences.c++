class Solution
{
    public:
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int, int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        int result = 0;
        
        for(auto it : mp)
        {
            if(it.second > n/k)
                result++;
        }
        
        return result;
        
    }
};
