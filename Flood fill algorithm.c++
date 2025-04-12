class Solution {
  public:
    int m, n;
    vector<vector<int>> dir {{0,1},{0,-1},{1,0},{-1,0}};
    
    void dfs(vector<vector<int>> &image, int i, int j, int val, int curr_color) {
        if(i<0 || i>=m || j<0 || j>=n || image[i][j] != curr_color)
            return ;
        
        image[i][j] = val;
        
        for(auto &it : dir) {
            int x = i + it[0];
            int y = j + it[1];
            
            dfs(image, x, y, val, curr_color);
        }
    }
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        n = image[0].size();
        
        int curr_color = image[sr][sc];
        
        if(curr_color != newColor)
            dfs(image, sr, sc, newColor, curr_color);
        
        return image;
    }
};
