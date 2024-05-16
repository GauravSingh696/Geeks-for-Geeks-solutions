class Solution{
    public:
    int minSubset(vector<int> &arr,int n){
        sort(arr.begin(), arr.end());
        long long int sum = 0;
        
        for(auto it : arr)
        {
            sum += it;
        }
        
        long long int value = 0;
        int count = 0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(value > sum)
            {
                break;
            }
            
            else
            {
                value += arr[i];
                sum -= arr[i];
                count++;
            }
        }
        
        return count;
    }
};
