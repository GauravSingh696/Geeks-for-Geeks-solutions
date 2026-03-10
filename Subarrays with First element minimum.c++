class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        stack<int> st;
        int n = arr.size();
        int result = 0;
        
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            int next_smaller = st.empty() ? n : st.top() ;
            result += next_smaller - i;
            st.push(i);
        }
        
        return result;
    }
};
