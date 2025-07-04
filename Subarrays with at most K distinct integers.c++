class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        int n = arr.size();
        int i = 0;
        int result = 0;
        
        for(int j=0;j<n;j++) {
            mp[arr[j]]++;
            
            while(mp.size() > k) {
                mp[arr[i]]--;
                
                if(mp[arr[i]] == 0)
                    mp.erase(arr[i]);
                
                i++;
            }
            
            result += j - i + 1;
        }
        
        return result;
    }
};
