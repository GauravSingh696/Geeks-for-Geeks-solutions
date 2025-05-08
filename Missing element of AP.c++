class Solution {
  public:
    int findMissing(vector<int> &arr) {
        unordered_map<int, int> mp;
        int n = arr.size();
        
        for(int i=1;i<n;i++) {
            int diff = arr[i] - arr[i-1];
            
            mp[diff]++;
        }
        
        int val = -1;
        int not_present = -1;
        
        for(auto &it : mp) {
            if(it.second > 1)
                val = it.first;
            
            else
                not_present = it.first;
        }
        
        if(val == -1)
            val = not_present;
    
        for(int i=0;i<n;i++) {
            if(arr[i]+val != arr[i+1])
                return arr[i] + val;
        }
        
        return arr[n-1] + val;
    }
};
