class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        string result = "";
        
        for(int i=0;i<arr[0].size();i++)
        {
            bool flag = true;
            
            for(int j=1;j<arr.size();j++)
            {
                if(arr[j][i] != arr[0][i])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag == false)
                break;
                
            else
                result += arr[0][i];
        }
        
        if(result.empty())
            return "-1";
        
        return result;
    }
};
