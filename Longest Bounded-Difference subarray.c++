class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        deque<int> max_que , min_que;
        int start =0 , end = 0;
        int n = arr.size();
        int res_start = 0 , res_end = 0;
        
        while(end<n) {
            while(!max_que.empty() && (arr[max_que.back()] < arr[end]))
                max_que.pop_back();
               
            while(!min_que.empty() && (arr[min_que.back()] > arr[end]))
                min_que.pop_back();
            
            min_que.push_back(end);
            max_que.push_back(end);
            
            while((arr[max_que.front()] - arr[min_que.front()])>x) {
                if(start == max_que.front())    max_que.pop_front();
                if(start == min_que.front())    min_que.pop_front();
                
                start++;
            }
            
            if((end - start) > (res_end - res_start)) {
                res_end = end;
                res_start = start;
            }
            
            end++;
        }
        
        vector<int> result;
        
        for(int i=res_start;i<=res_end;i++) {
            result.push_back(arr[i]);
        }
        
        return result;
    }
};
