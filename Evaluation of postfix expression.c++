class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        
        for(auto it : arr) {
            if(it=="+") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                st.push(a+b);
            }
            else if(it=="-") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                st.push(a-b);
            }
            else if(it=="*") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                st.push(a*b);
            }
            else if(it=="/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                st.push(a/b);
            }
            
            else {
                st.push(stoi(it));
            }
        }
        
        return st.top();
    }
};
