class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<int> next_greater(n, n), prev_greater(n, -1);
        stack<int> st1, st2;
        
        for(int i=0,j=n-1;i<n && j>=0;i++,j--) {
            // finding greater element...
            while(!st2.empty() && arr[st2.top()] <= arr[j]) {
                st2.pop();
            }
            
            if(st2.empty()) {
                next_greater[j] = n;
            } else {
                next_greater[j] = st2.top();
            }
            
            st2.push(j);
            
            
            // finding previous element...
            while(!st1.empty() && arr[st1.top()] <= arr[i]) {
                st1.pop();
            }
            
            if(st1.empty()) {
                prev_greater[i] = -1;
            } else {
                prev_greater[i] = st1.top();
            }
            
            st1.push(i);
        }
        
        int result = 0;
        
        for(int i=0;i<n;i++) {
            int len = next_greater[i] - prev_greater[i] - 1;
            
            if(len >= arr[i]) {
                result = max(result, len);
            }
        }
        
        return result;
    }
};
