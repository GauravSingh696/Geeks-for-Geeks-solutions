// 26-09-2024

class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        int result = 0;
        int count = 0;
        
        for(int i=1;i<arr.size();i++) {
            if(arr[i] > arr[i-1])
                count++;
            
            else
            {
                result = max(result , count);
                count = 0;
            }
        }
        
        result = max(result, count);
        
        return result;
    }
};
