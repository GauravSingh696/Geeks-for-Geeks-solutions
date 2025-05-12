class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        int m = meetings.size();
        vector<int> freq(n+1, 0);
        priority_queue<int, vector<int>, greater<int>> room;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        sort(meetings.begin(), meetings.end());
        
        for(int i=0;i<n;i++) {
            room.push(i);
        }
        
        for(int i=0;i<m;i++) {
            int st = meetings[i][0];
            int end = meetings[i][1];
            int duration = end - st;
            
            while(!pq.empty() && st >= pq.top().first) {
                int y = pq.top().second;
                pq.pop();
                room.push(y);
            }
            
            if(room.empty()) {
                int x = pq.top().first;
                int y = pq.top().second;
                pq.pop();
                
                pq.push(make_pair(x + duration, y));
                
                freq[y]++;
            }
            else {
                int book = room.top();
                room.pop();
                
                pq.push(make_pair(meetings[i][1], book));
                
                freq[book]++;
            }
        }
        
        int room_num = 0;
        int mx = 0;
        
        for(int i=0;i<n;i++) {
            if(freq[i] > mx) {
                mx = freq[i];
                room_num = i;
            }
        }
        
        return room_num;
    }
};
