// 04-06-2024

class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        
        int j, i, len = s.length();
        
        for(j=0;j<len;j++)
        {
            if(s[j] == '1')
                break;
        }
        
        string st = "";
        st.append(s.begin()+j , s.end());
        
        int size = st.length();
        
        
        for(i=size-1;i>=0;i--)
        {
            if(st[i]=='1')
                st[i] = '0';
            
            else
            {
                st[i] = '1';
                break;
            }
        }
        
        if(i < 0)
        {
            return "1" + st;
        }
        
        return st;
        
    }
};
