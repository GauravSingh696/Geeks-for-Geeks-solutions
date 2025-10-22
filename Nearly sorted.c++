class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<>> pq(arr.begin(), arr.begin()+k);
        int i = 0, j = k;
        int n = arr.size();
        
        while(j < n) {
            pq.push(arr[j]);
            arr[i++] = pq.top();
            pq.pop();
            j++;
        }
        
        while(!pq.empty()) {
            arr[i++] = pq.top();
            pq.pop();
        }
    }
};
