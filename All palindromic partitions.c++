class Solution {
  public:
    bool isPalindrome(string s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--])
                return false;
        }
        
        return true;
    }
  
    void dfs(int i, string s, vector<string> &path, vector<vector<string>> &result) {
        if(i >= s.size()) {
            result.push_back(path);
            return ;
        }
        
        for(int j=i;j<s.size();j++) {
            if(isPalindrome(s, i, j)) {
                path.push_back(s.substr(i, j-i+1));
                
                dfs(j+1, s, path, result);
                
                path.pop_back();
            }
        }
    }
  
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> result;
        vector<string> path;
        
        dfs(0, s, path, result);
        
        return result;
    }
};
