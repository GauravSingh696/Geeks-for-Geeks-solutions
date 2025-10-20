class Solution {
  public:
    int solve(int n) {
        if(n == 1 || n == 0)
            return 1;
        
        int ans = 0;
        
        for(int k=0;k<n;k++) {
            ans += solve(k) * solve(n - k - 1);
        }
        
        return ans;
    }
  
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mp;
        vector<int> res(n, 0);
        
        for(int i=0;i<n;i++) {
            mp[arr[i]] = i;
        }
        
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<n;i++) {
            int idx = mp[arr[i]];
            
            res[idx] = solve(i) * solve(n - i - 1);
        }
        
        return res;
    }
};
