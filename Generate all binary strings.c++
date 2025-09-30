class Solution {
  public:
    void solve(int i, int n, string &curr, vector<string> &result) {
        if(i > n)   return ;
        
        curr.push_back('0');
        if(i == n)  result.push_back(curr);
        solve(i+1, n, curr, result);
        curr.pop_back();
        
        curr.push_back('1');
        if(i == n)  result.push_back(curr);
        solve(i+1, n, curr, result);
        curr.pop_back();
    }
    
    vector<string> binstr(int n) {
        vector<string> result;
        string curr;
        
        solve(1, n, curr, result);
        
        return result;
    }
};
