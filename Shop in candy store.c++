class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size();
        int i=0, j=n-1;
        
        // for finding the minimum amount to purchase candies.
        int mini = 0;
        
        while(i <= j) {
            mini += prices[i++];
            j   -= k;
        }
        
        // for finding the maximum amount to purchase candies.
        int maxi = 0;
        i = 0, j=n-1;
        
        while(i <= j) {
            maxi += prices[j--];
            i    += k;
        }
        
        return {mini, maxi};
    }
};
