class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int i=0, j=0, k=0 ;
        int res = INT_MAX ;
        string str ;
        
        while(j < s1.length() && k < s2.length()) {
            if(s1[j] == s2[k])  k++ ;
            if(k == s2.length()) {
                i = j ;
                k = s2.length() - 1 ;
                
                while(i >= 0 && k >= 0) {
                    if(s1[i] == s2[k]) k-- ;
                    i-- ;   
                }
                
                i++ ;
                if(res > j-i+1) {
                    res = j-i+1 ;
                    str = s1.substr(i, j-i+1) ;
                }
                
                k=0 ;
                j = i+1 ;
            }
            
            j++ ;
        }
        
        return str ;
    }
};
