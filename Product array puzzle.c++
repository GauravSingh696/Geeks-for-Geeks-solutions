class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here       
        long long int mul;
        vector<long long int> result;
        
        for(int i=0;i<n;i++)
        {
            mul = 1;
            for(int j=0;j<n;j++)
            {
                if(j!=i)
                {
                    mul *= nums[j];
                }
            }
            
            result.push_back(mul);
        }
        
        return result;
    }
};
