class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n = arr.size() ; 
        vector<int>ans(n,-1);
        map<int,int>freq;
        stack<int>st;
        for(int i = 0 ; i<n ; i++) freq[arr[i]]++;
        
        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && freq[st.top()]<= freq[arr[i]]) st.pop();
            ans[i] = st.empty()?-1:st.top();
            st.push(arr[i]);
        }
        
        return ans;
    }
};
