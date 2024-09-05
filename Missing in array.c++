// 05-09-2024

class Solution {
  public:
    int missingNumber(int n, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int i = 0;
        
        for(i=0;i<n-1;i++)
        {
            if(arr[i] != i+1)
                return i+1;
        }
        
        return i+1;
        
    }
};
