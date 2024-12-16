class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int i=0,j=0 , n1=a.size() , n2=b.size() , cnt=0, val=0;
        while(cnt!=k && i<n1 && j<n2) {
            val=a[i]<b[j]?a[i++]:b[j++];
            cnt++;
        }
        if(cnt==k){
            return val;
        }
        while(i<n1 && cnt!=k) {
            val=a[i++];
            cnt++;
        }
        
        while(j<n2 && cnt!=k) {
            val=b[j++];
            cnt++;
        }
        
        return val;
    }
};
