// recursion approach...
class Solution {
public:
    string decodedString(string &s) {
        int i = 0;  
        return decode(s, i);  // start decoding from index 0
    }

private:
    string decode(string &s, int &i) {
        string ans = "";
        while(i < s.size() && s[i] != ']') {
            if(isdigit(s[i])) {
                int num = 0;
                while(i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');  // get the number
                    i++;
                }
                i++; // skip '['
                string inner = decode(s, i); // recursively decode inside []
                i++; // skip ']'
                while(num--) ans += inner;  // repeat decoded string
            } 
            else {
                ans += s[i]; // just append character
                i++;
            }
        }
        return ans;
    }
};



// brute force approach...
class Solution {
  public:
    string decodedString(string &s) {
        string ans;
        int n=s.size();
        stack<char> st;
        
        for(auto &ch : s) {
            if(ch!=']')
                st.push(ch);
                
            else {
                string temp="";
                
                while(!st.empty() && st.top()!='[') {
                    temp=st.top()+temp;
                    st.pop();
                }
                
                st.pop();
                string k="";
                
                while(!st.empty() && isdigit(st.top())) {
                    k=st.top()+k;
                    st.pop();
                }
                
                int count=stoi(k);
                string repeat="";
                
                while(count--)
                    repeat+=temp;
                
                for(char i:repeat)
                    st.push(i);
            }
        }
        
        while(!st.empty()) {
            ans=st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};
