// 13-06-2024

class Solution {
  public:
    int padovanSequence(int n) {
        // code here.
        vector<int> v(3,1);
        if(n<=2)
            return 1;
        int mod=1e9+7;
        int sum=0;
        for(int i=3 ; i<=n ; i++)
        {
            v.push_back((v[i-2]+v[i-3])%mod);
        }
        
        return v[n];
    }
};
