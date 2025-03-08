class Solution {
  public:
    bool isPalindrome(string &s, int i, int j, vector<vector<int>> &arr) {
        if(i>=j) {
            return 1;
        }
        
        if(arr[i][j] != -1)
            return arr[i][j];
        
        if(s[i] == s[j]) {
            return arr[i][j] = isPalindrome(s, i+1, j-1, arr);
        }
        
        return arr[i][j] = 0;
    }
  
    string longestPalindrome(string &s) {
        int n = s.size();
        int max_len = INT_MIN;
        int starting_idx = 0;
        vector<vector<int>> arr(n+1, vector<int>(n+1, -1));
        
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                if(isPalindrome(s, i, j, arr)) {
                    if((j-i+1) > max_len) {
                        max_len = j-i+1;
                        starting_idx = i;
                    }
                }
            }
        }
        
        return s.substr(starting_idx , max_len);
    }
};
