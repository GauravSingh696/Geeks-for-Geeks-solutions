class Solution {
  public:
    int sumSubstrings(string &s) {
        int result = 0;
        
        for(int i=0;i<s.size();i++) {
            string temp;
            
            for(int j=i;j<s.size();j++) {
                temp += s[j];
                
                result += stoi(temp);
            }
        }
        
        return result;
    }
};
