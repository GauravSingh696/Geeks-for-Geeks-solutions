class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;
        bool flag = true;
        
        for(char &ch : s) {
            if(!isalnum(ch)) {
                st.push(ch);
            } if(ch == ')') {
                st.pop();
                
                while(st.top() != '(') {
                    st.pop();
                    flag = false;
                }
                
                st.pop();
                
                if(flag) {
                    return true;
                }
            }
            
            flag = true;
        }
        
        return false;
    }
};
