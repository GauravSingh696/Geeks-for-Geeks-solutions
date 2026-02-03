class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        stack<int> st;
        int n = prices.size();
        
        for(int i=n-1;i>0;i--) {
            if(st.empty()) {
                st.push(i);
            }
            else {
                if(prices[st.top()] < prices[i])    st.push(i);
            }
        }
        
        int profit = 0;
        
        for(int i=0;i<n;i++) {
            while(!st.empty() && st.top() <= i) {
                st.pop();
            }
            
            if(st.empty())  break;
            
            if(prices[st.top()] > prices[i]) {
                profit = max(prices[st.top()]-prices[i], profit);
            }
        }
        
        return profit;
    }
};
