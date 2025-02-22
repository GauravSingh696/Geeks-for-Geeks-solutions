class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> v(n, -1);
        stack<int> st;
        for(int i=n-1 ; i>=0 ; i--) {
            while(!st.empty() && st.top()<=arr[i]) {
                st.pop();
            }
            
            if(!st.empty()){
                v[i]=st.top();
            }
            
            st.push(arr[i]);
        }
        
        return v;
    }
};
