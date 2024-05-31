class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        // vector<int> result;
        unordered_map<int,int> mp;
        for(int i=0 ; i<n ; i++)
        {
            mp[arr[i]]++;
        }
        
        int rep,mis;
        
        for(int i=1 ; i<=n ; i++)
        {
            if(mp[i]==2)
            {
                rep=i;
            }
            
            if(mp[i]==0)
            {
                mis=i;
            }
        }
        return {rep,mis};
    }
};
