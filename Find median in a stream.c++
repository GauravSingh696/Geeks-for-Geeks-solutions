class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<>> min_heap;
        vector<double> result;
        
        for(auto &it : arr) {
            if(max_heap.empty() || it <= max_heap.top()) {
                max_heap.push(it);
            }
            else
                min_heap.push(it);
            
            // balance the heap
            if(max_heap.size() > min_heap.size()+1) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            else if(max_heap.size() < min_heap.size()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            
            if(max_heap.size() == min_heap.size()) {
                double val = (max_heap.top() + min_heap.top()) / 2.0;
                result.push_back(val);
            }
            else {
                result.push_back(max_heap.top());
            }
        }
        
        return result;
    }
};
