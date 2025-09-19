class Solution {
  public:
    int minParentheses(string& s) {
        stack<char> st;
        int count = 0;
        for(auto &it: s) {
            if(it=='(') {
                st.push(it);
            } else{
                if(st.empty()) {
                    count++;
                } else{
                    st.pop();
                }
            }
        }
        while(!st.empty()) {
            count++;
            st.pop();
        }
        return count;
    }
};
