// 05-06-2024

class Solution {
 public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int sum1 = 0;     // sum of array a[] 
        int sum2=0;       //sum of array b[]
        
        for (int i=0 ; i<n ; i++)
        sum1+=a[i];
        
        for (int i=0 ; i<m ; i++)
        sum2+=b[i];
        
        int diff = abs(sum2-sum1);
        if (diff == 0)
            return 1;

        if (diff % 2 !=0)   // if diff of sum of both the arrays is odd 
            return -1 ;
            
        for(int i=0;i<n;i++)
        {
            if(diff==a[i])
                return 1;
        }
        
        for(int i=0;i<m;i++)
        {
            if(diff==b[i])
                return 1;
        }
        
        return -1;
    }
};
