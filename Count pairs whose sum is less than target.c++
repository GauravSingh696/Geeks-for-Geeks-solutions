class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int i=0 , j=arr.size()-1;
        int result = 0;
        
        sort(arr.begin() , arr.end());
        
        while(i<j) {
            while(j>i && arr[i]+arr[j]>=target)
                j--;
            
            result += j-i;
            i++;
        }
        
        return result;
    }
};
