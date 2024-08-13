// 13-08-2024

class Solution {
  public:
    long long int floorSqrt(long long int n) {
        
        for(long long int i=1;i<=n;i++)
        {
            if(i*i == n)
                return i;
            
            else if(i*i > n)
                return i-1;
        }
        
        return 0;
        
    }
};
