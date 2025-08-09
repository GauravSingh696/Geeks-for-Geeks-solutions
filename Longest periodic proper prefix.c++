class Solution {
  public:
    int getLongestPrefix(string &s) {
        int i=0, n = s.size();
        
        for(int i=n-1;i>0;i--) {
            if(s[i] == s[0]) {
                int a = 0;
                int b = i;
                
                while(b < n) {
                    if(s[a] != s[b])
                        break;
                    
                    a++, b++;
                }
                
                if(b == n)
                    return i;
            }
        }
        
        return -1;
    }
};
