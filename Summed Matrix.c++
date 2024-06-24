// 24-06-2024

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        
        if(q>n && q<=n+n)
        {
            return n+n - q + 1;
        }
        
        else if(q<=n+1)
        {
            return q - 1;
        }
        
        return 0;
        
    }
};
