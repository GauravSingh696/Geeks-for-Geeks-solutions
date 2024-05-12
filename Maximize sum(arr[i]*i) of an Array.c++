class Solution{
    int mod = 1e9+7;
    
    public:
    int Maximize(int a[],int n)
    {
        // Complete the function
        
        sort(a, a+n);
        
        long long int sum = 0;
        
        for(long long int i=0;i<n;i++)
        {
            sum = (sum + (i*a[i])%mod)%mod;
        }
        
        return sum;
    }
};
