 // 12-08-2024

class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        
        for(auto it : arr2)
        {
            arr1.push_back(it);
        }
        
        sort(arr1.begin(), arr1.end());
        
        int n = arr1.size();
        
        if(n%2==0)
            return arr1[(n/2) - 1] + arr1[n/2];
        else
            return arr1[n/2];
        
    }
};
