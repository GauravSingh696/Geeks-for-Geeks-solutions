class Solution {
public:
    static bool compare(pair<int, int> &a, pair<int, int> &b) {
        if(a.first == b.first) {
            return a.second > b.second;
        }
        
        return a.first>b.first;
    }

    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int,int> mp;
        vector<pair<int,int>> v;
        vector<int> ans;
        
        for (auto it : arr) {
            mp[it]++;
        }

        for (auto it : mp) {
            v.push_back({it.second, it.first}); 
        }
        
        sort(v.begin(), v.end(), compare);

        for (auto it : v) {
            ans.push_back(it.second);
            k--;
            
            if (k == 0) break;
        }

        return ans;
    }
};
