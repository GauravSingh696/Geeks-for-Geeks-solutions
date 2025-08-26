class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        vector<int> idx;
        int n1 = s1.size();
        int n2 = s2.size();
        
        for(int i=0;i<n2;i++) {
            if(s2[i] == s1[0])
                idx.push_back(i);
        }
        
        for(int curr=0;curr<idx.size();curr++) {
            int i=0, j=idx[curr];
            
            while(i<n1 && j<n2) {
                if(s1[i] == s2[j]) {
                    i++, j++;
                }
                
                else {
                    j++;
                }
            }
            
            if(i == n1)
                return true;
        }
        
        return false;
    }
};
