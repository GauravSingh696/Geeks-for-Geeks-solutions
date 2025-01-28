class Solution {
  public:
    vector<string> findPermutation(string &s) {
        vector<string> result;
        sort(s.begin() , s.end());
        
        do {
            result.push_back(s);
        } while(next_permutation(s.begin() , s.end()));
        
        return result;
    }
};
