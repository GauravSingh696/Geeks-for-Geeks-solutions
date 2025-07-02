class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> mp;
        int i = 0;
        int n = arr.size();
        int result = 0;
        
        for(int j=0;j<n;j++) {
            mp[arr[j]]++;
            
            while(mp.size() > 2) {
                mp[arr[i]]--;
                
                if(mp[arr[i]] == 0)
                    mp.erase(arr[i]);
                
                i++;
            }
            
            result = max(result, j-i+1);
        }
        
        return result;
    }
};
