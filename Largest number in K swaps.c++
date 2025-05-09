class Solution {
  public:
    void solve(string &result, string str, int k, int idx) {
        if(k==0 || idx>=str.size())
            return ;
        
        char maxChar = str[idx];
        
        for(int i=idx+1;i<str.size();i++) {
            if(str[i] > maxChar)
                maxChar = str[i];
        }
        
        if(maxChar != str[idx])
            k--;
            
        for(int i=idx;i<str.size();i++) {
            if(maxChar == str[i]) {
                swap(str[idx] , str[i]);
                
                if(str.compare(result) > 0)
                    result = str;
                
                solve(result, str, k, idx+1);
                swap(str[idx], str[i]);
            }
        }
    }
  
    string findMaximumNum(string& s, int k) {
        string result = s;
        
        solve(result, s, k, 0);
        
        return result;
    }
};
