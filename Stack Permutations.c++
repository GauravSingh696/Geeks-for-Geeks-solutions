class Solution{
public:
    int isStackPermutation(int n,vector<int> &a,vector<int> &b){
        vector<int> vec;
        stack<int> st;
        int i=0 , j=0;
        
        while(i<n)
        {
            st.push(a[i]);
            
            while(!st.empty() && st.top() == b[j])
            {
                vec.push_back(b[j++]);
                st.pop();
            }
            
            i++;
        }
        
        return vec == b;
    }
};
