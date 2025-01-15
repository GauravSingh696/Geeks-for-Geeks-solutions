class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int result = 0 , sum = 0;
        
        for(int i=0;i<arr.size();i++) {
            if(mp.fin
            d(sum) == mp.end()) {
                mp[sum] = i;
            }
            
            sum += arr[i];
            
            if(mp.find(sum-k) != mp.end()) {
                result = max(result , i-mp[sum-k] + 1);
            }
        }
        
        return result;
    }
};
