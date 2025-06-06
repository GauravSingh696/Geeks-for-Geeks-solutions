class Solution {
  public:
    vector<int> search(string &pattern, string &text) {
        int n = pattern.size();
        int m = text.size();
        
        vector<int>lps(n, 0);
        int len = 0;
        
        for(int i=1;i<n;i++) {
            while(len > 0 && pattern[len] != pattern[i])
                len = lps[len - 1];
            
            if(pattern[len] == pattern[i])
                len++;
            
            lps[i] = len;
        }
        
        vector<int> result;
        int j = 0;
        
        for(int i=0;i<m;i++) {
            while(j > 0 && pattern[j] != text[i])
                j = lps[j - 1];
                
            if(text[i] == pattern[j])
                j++;
            
            if(j == n) {
                result.push_back(i - n + 2);
                j = lps[n - 1];
            }
        }
        
        return result;
    }
};
