class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        vector<int> res(26,0);
        for(char it:s) {
            res[it-'a']++;
        }
        
        for(char it:s) {
            if(res[it-'a']==1) {
                return it;
            }
        }
        
        return '$';
    }
};
