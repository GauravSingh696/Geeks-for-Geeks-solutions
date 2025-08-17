class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        map<int, vector<int>> mp;
        
        for(auto &it : arr) {
            mp[abs(it - x)].push_back(it);
        }
        
        int i=0;
        
        for(auto &it : mp) {
            for(int val : it.second) {
                arr[i++] = val;
            }
        }
    }
};
