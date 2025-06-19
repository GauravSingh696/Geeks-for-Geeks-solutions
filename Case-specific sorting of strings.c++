class Solution {
  public:
    string caseSort(string& s) {
        string uppercase, lowercase;
        
        for(char &ch : s) {
            if(ch >= 'a' && ch <='z')
                lowercase.push_back(ch);
            
            else
                uppercase.push_back(ch);
        }
        
        sort(uppercase.begin(), uppercase.end());
        sort(lowercase.begin(), lowercase.end());
        
        int i = 0, j = 0, k = 0;
        string result;
        
        for(int k=0;k<s.size();k++) {
            if(s[k] >= 'a' && s[k] <='z') {
                result.push_back(lowercase[i]);
                i++;
            }
            
            else {
                result.push_back(uppercase[j]);
                j++;
            }
        }
        
        return result;
    }
};
