class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        
        if(n<2) return {};
        
        sort(arr.begin(), arr.end());
        
        int i=0 , j=n-1;
        int diff = INT_MAX;
        int val1 = -1 , val2 = -1;
        
        while(i<j) {
            int d = abs(target - (arr[i]+arr[j]));
            
            if(d<diff) {
                diff = d;
                val1 = arr[i] , val2 = arr[j];
            }
            
            else if(arr[i]+arr[j] < target) {
                i++;
            }
            
            else if(arr[i]+arr[j] >= target) {
                j--;
            }
        }
        
        return {val1 , val2};
    }
};
