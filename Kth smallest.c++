// 19-08-2024

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pr;
        
        for(auto it : arr)
        {
            pr.push(it);
            
            if(pr.size() > k)
                pr.pop();
        }
        
        return pr.top();
    }
};
