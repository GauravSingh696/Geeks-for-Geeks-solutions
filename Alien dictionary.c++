class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<bool> present(26, false);
        vector<int> indegree(26, 0);
        
        for(auto &it : words) {
            for(auto &ch : it) {
                present[ch-'a'] = true;
            }
        }
        
        for(int i=0;i<n-1;i++) {
            string str1 = words[i];
            string str2 = words[i+1];
            int len = min(str1.size() , str2.size());
            bool check = false;
            
            for(int i=0;i<len;i++) {
                if(str1[i] != str2[i]) {
                    adj[str1[i] - 'a'].push_back(str2[i] - 'a');
                    indegree[str2[i] - 'a']++;
                    check = true;
                    break;
                }
            }
            
            if(!check && str1.size() > str2.size())
                return "";
        }
        
        queue<int> que;
        
        for(int i=0;i<26;i++) {
            if(present[i] && indegree[i] == 0)
                que.push(i);
        }
        
        string ans;
        
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            ans += char(node + 'a');
            
            for(auto &it : adj[node]) {
                indegree[it]--;
                
                if(indegree[it] == 0)
                    que.push(it);
            }
        }
        
        for(int i=0;i<26;i++) {
            if(present[i] && indegree[i] > 0)
                return "";
        }
        
        return ans;
    }
};
