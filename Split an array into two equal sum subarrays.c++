// 18-08-2024

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        
        int n = arr.size();
        int sum = 0;
        
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            arr[i] = sum;
        }
        
        int i = 0;
        int j = n-1;
        
        while(i<j)
        {
            if((arr[j] - arr[i]) == arr[i])
                return true;
            
            i++;
        }
        
        return false;
        
    }
};
