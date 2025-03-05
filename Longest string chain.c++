class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> mp;
        int longest = 1;

        for (auto &it : words) {
            mp[it] = 1;
            
            for (int i = 0; i < it.size(); ++i) {
                string predecessor = it.substr(0, i) + it.substr(i + 1);
                
                if (mp.find(predecessor) != mp.end()) {
                    mp[it] = max(mp[it], mp[predecessor] + 1);
                }
            }
            
            longest = max(longest, mp[it]);
        }

        return longest;
    }
};
