// 01-06-2024

class Solution {
  public:
    string oddEven(string s) {
        // code here
        
        int len = s.length();
        unordered_map<char, int> mp;
        
        for(int i=0;i<len;i++)
        {
            mp[s[i]]++;
        }
        
        int even = 0 , odd = 0;
        
        for(auto &it : mp)
        {
            if((it.second%2) == 0  && (it.first - 60)%2 == 0)
            {
                even++;
            }
            
            if((it.second%2) != 0  && (it.first - 60)%2 != 0)
            {
                odd++;
            }
        }
        
        int find = even + odd;
        
        return find%2==0 ? "EVEN" : "ODD";
        
    }
};
