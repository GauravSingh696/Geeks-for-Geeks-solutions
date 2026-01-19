class Solution {
  public:
    string removeKdig(string &s, int k) {
        string result;
        
        for(int i=0;i<s.size();i++) {
            while(result.size() != 0 && result.back() > s[i] && k > 0) {
                result.pop_back();
                k--;
            }
            result += s[i];
        }
        
        while(result.size() != 0 && k > 0) {
            result.pop_back();
            k--;
        }
        
        int count = 0;
        
        for(auto &ch : result) {
            if(ch-'0' == 0) {
                count++;
            } else {
                break;
            }
        }
        
        if(count == result.size()) {
            return "0";
        } else {
            return result.substr(count, result.size());
        }
    }
};
