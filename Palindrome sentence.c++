class Solution {
  public:
    bool isPalinSent(string &s) {
        string res;
        
        for(char &ch : s) {
            if(isalnum(ch)) {
                res.push_back(tolower(ch));
            }
        }
        
        int i=0, j=res.size()-1;
        
        while(i<j) {
            if(res[i] != res[j])
                return false;
            
            i++, j--;
        }
        
        return true;
    }
};
