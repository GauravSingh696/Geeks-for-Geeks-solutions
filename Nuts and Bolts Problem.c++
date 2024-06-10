// 10-06-2024

class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        char size[9]={'!', '#', '$', '%', '&', '*', '?', '@', '^'};
        unordered_map<char,int> mp;
        for(int i=0 ; i<n ; i++)
        {
            mp[nuts[i]]++;
        }

        int z=0;
        for(int i=0 ; i<9 ; i++)
        {
            char x=size[i];
            if(mp.find(x) != mp.end())
            {
                nuts[z]=x;
                bolts[z]=x;
                z++;
            }
        }
    }
};
