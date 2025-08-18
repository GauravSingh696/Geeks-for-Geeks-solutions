class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        sort(citations.rbegin(), citations.rend());
        int maxi = 0;
        
        for(int i=0 ; i<citations.size() ; i++) {
            if(citations[i]>=i+1) {
                maxi = i+1;
            } else {
                break;
            }
        }
        
        return maxi;
    }
};
