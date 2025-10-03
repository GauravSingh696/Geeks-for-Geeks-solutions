class Solution {
  public:
    void solve(int i, vector<int> &arr, vector<string> &result, string &s, unordered_map<int, string> &mp) {
        if(i >= arr.size()) {
            result.push_back(s);
            return ;
        }
        
        int n = arr[i];
        
        if(n == 1 || n == 0) {
            solve(i+1, arr, result, s, mp);
        }
        
        for(int j=0;j<mp[n].size();j++) {
            s.push_back(mp[n][j]);
            solve(i+1, arr, result, s, mp);
            s.pop_back();
        }
    }
  
    vector<string> possibleWords(vector<int> &arr) {
        unordered_map<int, string> mp;
        mp[2] = "abc", mp[3] = "def", mp[4] = "ghi", mp[5] = "jkl";
        mp[6] = "mno", mp[7] = "pqrs", mp[8] = "tuv", mp[9] = "wxyz";
        
        vector<string> result;
        string s;
        
        solve(0, arr, result, s, mp);
        
        return result;
    }
};
