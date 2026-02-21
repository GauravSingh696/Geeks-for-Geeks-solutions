// 1st approach...
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


// 2nd approach...
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n+1);
        
        for(int i=0;i<n;i++) {
            if(citations[i] >= n)   freq[n]++;
            else    freq[citations[i]]++;
        }
        
        int maxi = n;
        int num = freq[n];
        
        while(num < maxi) {
            maxi--;
            num += freq[maxi];
        }
        
        return maxi;
    }
};
