class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int one = 0, zero = 0;
        int i=0, j=0;
        int result = 0;
        
        for(int j=0;j<arr.size();j++) {
            if(arr[j] == 0) zero++;
            
            while(i<=j && zero > k) {
                if(arr[i] == 0) zero--;
                
                i++;
            }
            
            result = max(result, j-i+1);
        }
        
        return result;
    }
};
