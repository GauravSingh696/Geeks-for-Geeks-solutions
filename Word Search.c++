class Solution {
  public:
    bool check_boundary(int i, int j, int m, int n) {
        return (i>=0 && j>=0 && i<m && j<n);
    }
    
    bool solve(int i, int j, int idx, int m, int n, vector<vector<char>> &mat, string &word, set<pair<int, int>> &visited) {
        if(idx == word.size())
            return true;
        
        if(!check_boundary(i, j, m, n))
            return false;
            
        int dir[] = {-1, 0, 1, 0, -1};
        
        visited.insert(make_pair(i, j));
        
        for(int k=0;k<4;k++) {
            int i_ = i + dir[k];
            int j_ = j + dir[k+1];
            
            if(check_boundary(i_, j_, m, n) && (word[idx] == mat[i_][j_]) && (visited.find(make_pair(i_, j_)) == visited.end())) {
                if(solve(i_, j_, idx+1, m, n, mat, word, visited)) {
                    return true;
                }
            }
        }
        
        visited.erase(make_pair(i, j));
        
        return false;
    }
  
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int m = mat.size() , n = mat[0].size();
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(word[0] == mat[i][j]) {
                    set<pair<int, int>> visited;
                    
                    if(solve(i, j, 1, m, n, mat, word, visited))
                        return true;
                }
            }
        }
        
        return false;
    }
};
