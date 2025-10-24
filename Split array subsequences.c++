class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        unordered_map<int, int> freq, end;
        
        for(int it : arr) {
            freq[it]++;
        }
        
        for(int it : arr) {
            if(freq[it] == 0) {
                continue;
            }
            
            if(end[it-1] > 0) {
                end[it-1]--;
                end[it]++;
                freq[it]--;
            } else {
                bool canStart = true;
                
                for(int i=0;i<k;i++) {
                    if(freq[it+i] == 0) {
                        canStart = false;
                        break;
                    }
                }
                
                if(!canStart)
                    return false;
                
                for(int i=0;i<k;i++) {
                    freq[it+i]--;
                }
                
                end[it+k-1]++;
            }
        }
        
        return true;
    }
};
