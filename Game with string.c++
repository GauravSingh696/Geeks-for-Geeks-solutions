class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        unordered_map<char,int> mp;
        
        for(char &ch : s) {
            mp[ch]++;
        }
        
        priority_queue<int> pq;
        
        for(auto &it : mp) {
            pq.push(it.second);
        }
        
        while(k-- && !pq.empty()) {
            int x = pq.top();
            pq.pop();
            
            if(x != 1)
                pq.push(--x);
        }
        
        int sum = 0;
        
        while(!pq.empty()) {
            sum += pq.top()*pq.top();
            pq.pop();
        }
        
        return sum;
    }
};
