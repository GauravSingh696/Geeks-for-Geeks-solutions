class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> next_greater(n, n), prev_greater(n, -1);
        int result = 0;
        
        // next greater.
        for(int i=0;i<n;i++) {
            while(!st.empty() && arr[i] >= arr[st.top()]) {
                next_greater[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }
        
        // previous greater.
        while(!st.empty())  st.pop();
        
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && arr[i] >= arr[st.top()]) {
                prev_greater[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }
        
        for(int i=0;i<n;i++) {
            result = max(result, next_greater[i]-prev_greater[i]-1);
        }
        
        return result;
    }
};
