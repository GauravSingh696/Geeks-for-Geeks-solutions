class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    set<char> res;
	    string ans="";
	    for(auto ch:str)
	    {
	        if(res.find(ch)==res.end())
	        {
	            ans+=ch;
	            res.insert(ch);
	        }
	    }
	    return ans;
	}
};
