class Solution {
  public:
    string countAndSay(int n) {
        // code here
        string prev = "1",s;
        
        if(n==1) 
            return prev;
        
        for(int i=1;i<n;i++) {
            int c =0,m=prev.size();
            s = "";
            
            for(int j=0;j<m;j++) {
                c++;
                
                if(j< m-1 && prev[j]!=prev[j+1]) {
                    s.push_back(c+48);
                    s.push_back(prev[j]);
                    c=0;
                }
            }
            
            if(c) {
                s.push_back(c+48);
                s.push_back(prev[m-1]);
            }
            
            prev = s;
        }
        
        return s;
    }
};
