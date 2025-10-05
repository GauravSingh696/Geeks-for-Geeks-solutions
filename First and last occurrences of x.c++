class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> result;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] == x)
            {
                result.push_back(i);
                
                while(arr[i] == arr[i+1])
                {
                    i++;
                }
                
                result.push_back(i);
                
                break;
            }
        }
        
        if(result.empty())
        {
            result.push_back(-1);
            result.push_back(-1);
        }
        
        return result;
    }
};
