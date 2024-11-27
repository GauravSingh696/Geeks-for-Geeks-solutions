class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        int i=0 , j=0;
        int n = arr.size();
        int count = 0 , result = 0;
        
        while(j<n) {
            if(arr[j] == 0) 
                count++;
            
            while(count == k+1) {
                result = max(result , j-i);
                if(arr[i] == 0)
                    count--;
                i++;
            }
            
            j++;
        }
        
        if(count <= k && j == n) {
            result = max(result , j-i);
        }
        
        return result;
    }
};
