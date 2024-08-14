// 14-08-2024

class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        
        int len1 = str1.length();
        int result = 0;
        
        for(int i=0;i<len1;i++)
        {
            string temp = "";
            
            for(int j=i;j<len1;j++)
            {
                temp += str1[j];
                int m = str2.find(temp);
                
                if(m >= 0)
                {
                    int n = temp.length();
                    result = max(result, n);
                }
            }
        }
        
        return result;
    }
};
