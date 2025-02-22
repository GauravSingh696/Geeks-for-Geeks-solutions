class Solution {
  public:
    int maxLength(string& s) {
        int n = s.size();
        int left = 0, right = 0;
        int result = 0;
        
        for(auto &it : s) {
            if(it == '(' || it == '{' || it == '[') {
                left++;
            }
            if(it == ')' || it == '}' || it == ']') {
                right++;
            }
            
            if(left == right) {
                result = max(result, left*2);
            }
            
            if(right > left) {
                left = right = 0;
            }
        }
        
        left = 0 , right = 0;
        
        for(int i=n-1;i>=0;i--) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                left++;
            }
            if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                right++;
            }
            
            if(left == right) {
                result = max(result, left*2);
            }
            
            if(right < left) {
                left = right = 0;
            }
        }
        
        return result;
    }
};
