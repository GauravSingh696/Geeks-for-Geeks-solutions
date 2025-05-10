class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> vec(n);
        
        for(int i=0;i<n;i++) {
            if(arr[i] > k) {
                vec[i] = 1;
            }
            
            else {
                vec[i] = -1;
            }
        }
        
        unordered_map<int, int> mp;
        int prefix = 0 , result = 0;
        
        for(int i=0;i<n;i++) {
            prefix += vec[i];
            
            if(prefix > 0)
                result = i+1;
            
            else {
                if(mp.find(prefix-1) != mp.end()) {
                    result = max(result, i-mp[prefix-1]);
                }
            }
            
            if(mp.find(prefix) == mp.end())
                mp[prefix] = i;
        }
        
        return result;
    }
};
