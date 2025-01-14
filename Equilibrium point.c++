class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        unordered_map<int, int> mp;
        
        int sum = 0;
        
        for(int i=0;i<arr.size()-1;i++) {
            sum += arr[i];
            
            if(mp.find(sum) == mp.end()) 
                mp[sum] = i+1;
        }
        
        sum = 0;
    
        for(int i=arr.size()-1;i>1;i--) {
            sum += arr[i];
        
            if(mp[sum] == i-1)
                return mp[sum];
        }
    
        return -1;
    }
};
