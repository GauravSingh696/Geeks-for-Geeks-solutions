// 06-08-2024

class Solution {
  public:
    int isValid(string str) {
        int n = str.length();
        
        if(str[0] == '.' || str[n-1] == '.')
            return false;
        
        int c = count(str.begin(), str.end(), '.');
        
        if(c == 3)
        {
            for(int i=0;i<n-1;i++)
            {
                if(str[i] == '.' && str[i] == str[i+1])
                    return false;
            }
            
            string st = "";
            vector<int> vec;
            
            for(int i=0;i<n;i++)
            {
                if(str[i] != '.')
                {
                    st += str[i];
                }
                
                else
                {
                    if(st.length() > 1 && st[0] == '0')
                        return false;
                    
                    vec.push_back(stoi(st));
                    st = "";
                }
            }
            
            if(st.length() > 1 && st[0] == '0')
                return false;
            vec.push_back(stoi(st));
            
            for(auto it : vec)
            {
                if(it < 0 || it > 255)
                    return false;
            }
            
            return true;
        }
        
        else
            return false;
        
    }
};
