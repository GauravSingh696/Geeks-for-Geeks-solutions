// 17-05-2024

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        
        if(n==1)
            return -1;
        
        int i=0;
        int j=1;
        
        sort(arr.begin(), arr.end());
        
        while(i<n && j<n)
        {
            int diff = arr[j]-arr[i];
            
            if(diff < x)
                j++;
            
            else if(diff > x)
                i++;
            
            else
                return 1;
            
            if(i==j)
                j++;
        }
        
        return -1;
    }
};
