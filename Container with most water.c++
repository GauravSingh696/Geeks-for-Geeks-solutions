class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int result = 0;
        int i = 0;
        int j = arr.size()-1;
        
        while(i < j){
            int area = min(arr[i],arr[j]) * (j - i);
            
            result = max(area ,result );
            
            arr[i]<arr[j] ? i++ : j-- ;
        }
        
        return result;
    }
};
