class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        int i=0 , j=0;
        
        unordered_map<int,int> mp;
        vector<int> result;
        
        while(j<n) {
            mp[arr[j]]++;
            
            if(j-i+1 == k) {
                result.push_back(mp.size());
                
                mp[arr[i]]--;
                
                if(mp[arr[i]] == 0)
                    mp.erase(arr[i]);
                
                i++;
            }
            
            j++;
        }
        
        return result;
    }
};
