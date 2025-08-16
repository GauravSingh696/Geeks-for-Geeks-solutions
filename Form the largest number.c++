class Solution {
  public:
    static bool cmp(int a, int b) {
        return (to_string(a) + to_string(b)) > (to_string(b) + to_string(a));
    }
  
    string findLargest(vector<int> &arr) {
        sort(arr.begin(), arr.end(), cmp);
        
        string result;
        int zero = 0;
        
        for(auto &it : arr) {
            if(it == 0)  zero++;
            
            result += to_string(it);
        }
        
        return zero == arr.size() ? "0" : result ;
    }
};
