// 23-06-2024

class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        
        int len = str.length();
        int count = 1;
        
        stack<int> st;
        
        vector<int> result;
        
        for(int i=0;i<len;i++)
        {
            if(str[i] == '(')
            {
                result.push_back(count);
                st.push(count++);
            }
            
            else if(str[i] == ')')
            {
                result.push_back(st.top());
                st.pop();
            }
        }
        
        return result;
    }
};
