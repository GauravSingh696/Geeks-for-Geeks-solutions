class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        unordered_set<int> st(arr.begin() , arr.end());
        
        int n=arr.size();
        int b=arr[n-1];
      
        for(int i=1;i<b;i++){
            if(st.find(i) == st.end()){
                k--;
                if(k==0){
                    return i;
                }
            }
        }
        
        while(k--){
            b++;
        }
        
        return b;
    }
};
