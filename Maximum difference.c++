// 27-08-2024

class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        
        int n = arr.size();
        vector<int> ls , rs;
        
        for(int i=0;i<n;i++)
        {
            int val = 0;
            
            for(int j=i-1;j>=0;j--)
            {
                if(arr[j] < arr[i])
                {
                    val = arr[j];
                    break;
                }
            }
            
            ls.push_back(val);
            val = 0;
            
            for(int j=i+1;j<n;j++)
            {
                if(arr[j] < arr[i])
                {
                    val = arr[j];
                    break;
                }
            }
            
            rs.push_back(val);
        }
        
        int result = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            result = max(result , abs(ls[i] - rs[i]));
        }
        
        return result;
        
    }
};
