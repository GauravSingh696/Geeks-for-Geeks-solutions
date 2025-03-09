// approach 1st

class Solution {
  public:
    vector<vector<int>> vec;
  
    int check(string &s, int i, int j) {
        if(i>=j)
            return 1;
        
        if(vec[i][j] != -1)
            return vec[i][j];
        
        if(s[i] == s[j])
            return vec[i][j] = check(s, i+1, j-1);
        
        return vec[i][j] = 0;
    }
  
    int countPS(string &s) {
        int n = s.size();
        int result = 0;
        vec.assign(n+1, vector<int>(n+1, -1));
        
        for(int i=0;i<n;i++ ) {
            for(int j=i+1;j<n;j++) {
                if(check(s, i, j))
                    result++;
            }
        }
        
        return result;
    }
};



// approach 2nd

class Solution {
  public:
    int count;
    
    void solve(string &s, int i, int j, int n) {
        while(i>=0 && j<n && s[i] == s[j]) {
            if(j-i >= 1) 
                count++;
            
            i--;
            j++;
        }
    }
  
    int countPS(string &s) {
        int n = s.size();
        count = 0;
        
        for(int i=0;i<n;i++ ) {
            solve(s, i, i, n);
            solve(s, i, i+1, n);
        }
        
        return count;
    }
};
