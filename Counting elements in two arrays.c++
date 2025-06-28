// approach 1st

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        sort(b.begin(), b.end());
        vector<int> result;
        
        for (int x : a) {
            int count = upper_bound(b.begin(), b.end(), x) - b.begin();
            result.push_back(count);
        }
        
        return result;
    }
};


// approach 2nd

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());
        
        map<int, int> mp;
        
        for(int i=0;i<b.size();i++) {
            mp[b[i]] = i+1;
        }
        
        vector<int> result;
        int n = b.size();
        
        for(int &it : a) {
            if(mp[it] > 0) {
                result.push_back(mp[it]);
                continue;
            }
            
            
            if(b[n-1] < it) {
                result.push_back(n);
                continue;
            }
            
            for(int i=0;i<n;i++) {
                if(b[i] > it) {
                    result.push_back(i);
                    break;
                }
            }
        }
        
        return result;
    }
};
