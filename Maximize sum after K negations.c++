class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        
        sort(a , a+n);
        
        for(int i=0;i<n;i++)
        {
            if(k == 0)
                break;
            
            if(a[i] < 0)
            {
                k--;
                a[i] *= -1;
            }
        }
        
        if(k != 0)
        {
            sort(a, a+n);
            
            if(k%2 != 0)
                a[0] *= -1;
        }
        
        long long int result = 0;
        
        for(int i=0;i<n;i++)
        {
            result += a[i];
        }
        
        return result;
        
    }
};
