class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int mul1 = 1 , mul2 = 1;
        int n = arr.size();
        
        int result = INT_MIN;
        
        for(int i=0 , j=n-1 ; i<n , j>=0 ; i++ , j--) {
            if(mul1 == 0) {
                mul1 = 1;
            }
            if(mul2 == 0) {
                mul2 = 1;
            }
            
            mul1 *= arr[i] , mul2 *= arr[j];
            result = max({result , mul1 , mul2});
        }
        
        return result;
    }
};
