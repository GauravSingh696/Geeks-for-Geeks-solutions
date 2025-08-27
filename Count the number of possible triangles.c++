class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        
        sort(arr.begin(), arr.end());
        
        for(int i=2;i<n;i++) {
            int left = 0, right = i-1;
            
            while(left < right) {
                int sum = arr[left] + arr[right];
                
                if(sum > arr[i]) {
                    result += right - left;
                    right--;
                } else {
                    left++;
                }
            }
        }
        
        return result;
    }
};
