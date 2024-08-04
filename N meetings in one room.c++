// 04-08-2024

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        int s = -1;
        int result = 0;
        
        vector<pair<int, int>> pr;
        
        for(int i=0;i<n;i++)
        {
            pr.push_back({end[i] , start[i]});
        }
        
        sort(pr.begin(), pr.end());
        
        for(auto it : pr)
        {
            if(it.second > s)
            {
                result++;
                s = it.first;
            }
        }
        
        return result;
    }
};
