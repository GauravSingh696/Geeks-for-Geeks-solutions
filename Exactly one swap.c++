class Solution {
  public:
    int countStrings(string &s) {
        int count=0,l=s.length();
        unordered_map<char,int> mp;
        bool flag=false;
        
        for(char ch : s) {
            mp[ch]++;
        }
        
        for(char ch : s) {
            if(mp[ch] > 1)
                flag=true;
                
            count += l - mp[ch];
        }
        
        count /= 2;
        
        if(flag)
            count++;
            
        return count;
    }
};
