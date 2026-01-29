class Solution {
  public:
    string firstNonRepeating(string &s) {
        queue<char> que;
        unordered_map<char, int> mp;
        string result;
        
        for(auto it : s) {
            mp[it]++;
            
            if(mp[it] == 1) que.push(it);
            
            while(!que.empty() && mp[que.front()] > 1) {
                que.pop();
            }
            
            if(que.empty()) {
                result += "#";
            } else {
                result += que.front();
            }
        }
        
        return result;
    }
};
