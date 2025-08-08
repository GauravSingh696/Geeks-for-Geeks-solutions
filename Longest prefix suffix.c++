class Solution {
  public:
    int getLPSLength(string &str) {
        int p=0, s=1;
        int pos = 1, count = 0;
        int n = str.size();
        
        while(s<n) {
            if(str[p] == str[s]) {
                p++, s++;
                count++;
            }
            
            else {
                p = 0;
                pos++;
                s = pos;
                count = 0;
            }
        }
        
        return count;
    }
};
