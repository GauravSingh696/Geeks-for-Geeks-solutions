// 29-07-2024

class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        
        int row = arr.size();
        
        int result = -1;
        int prev = 0;
        
        for(int i=0;i<row;i++)
        {
            int c = count(arr[i].begin(), arr[i].end(), 1);
            
            if(prev < c)
                result = i;
            
            if(c == arr[i].size())
                break;
                
            prev = max(prev , c);
        }
        
        return result;
        
    }
};
