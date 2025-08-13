class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int troop = 0;
        vector<int> vec;
        
        for(int &it : arr) {
            if(it%k == 0)
                troop++;
            else {
                int val = k - (it%k);
                vec.push_back(val);
            }
        }
        
        int n = ceil(arr.size()/2.0);
        
        if(troop >= n)
            return 0;
        
        sort(vec.begin(), vec.end());
        int result = 0;
        
        for(int i=0;i<n-troop;i++) {
            result += vec[i];
        }
        
        return result;
    }
};
