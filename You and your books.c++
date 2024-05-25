// 25-05-2024

#include<vector>

class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        long long int result = 0;
        int i=0;
        long long int curr = 0;
        
        if(*min_element(arr , arr+n) > k)
            return 0;
        
        while(i<n)
        {
            if(arr[i] <= k)
            {
                curr += arr[i];
            }
            
            else
                curr = 0;
            
            result = max(result , curr);
            i++;
            
        }
        
        return result;
        
    }
};
