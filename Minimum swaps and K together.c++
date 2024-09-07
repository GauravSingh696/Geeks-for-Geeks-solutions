class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        
        int count = 0;
        for(int i=0;i<n;i++)
            if(arr[i] <= k)
                count++;
        
        int i=0 , j=0;
        int result = INT_MAX , cnt = 0;
        
        while(j<n)
        {
            if(arr[j] > k)
                cnt++;
            
            while(j-i+1 == count)
            {
                result = min(result , cnt);
                if(arr[i] > k)
                    cnt--;
                i++;
            }
            
            j++;
        }
        
        return result==INT_MAX ? 0 : result ;
        
    }
};
