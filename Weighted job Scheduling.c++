class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b){
            return a[1] < b[1]; // sort by end time
        });

        map<int, int> dp;  // {end_time, max_profit_till_that_time}
        dp[0] = 0;

        for (auto &job : jobs) {
            int start = job[0], end = job[1], profit = job[2];
            // find last job that ends <= current start
            auto it = dp.upper_bound(start);
            it--;
            int curr = it->second + profit;

            dp[end] = max(dp.rbegin()->second, curr);
        }

        return dp.rbegin()->second;
    }
}; 
