class Solution {
public:
    bool ispolindrome(int num)
    {
        int n = num;
        int rev = 0;
        
        while(num)
        {
            int rem = num%10;
            rev = rev*10 + rem;
            num /=10;
        }
        
        if(rev==n)
            return true;
        
        else
            return false;
    }

    int PalinArray(int a[], int n)
    {
    	// code here
    	
    	for(int i=0;i<n;i++)
    	{
    	    if(!ispolindrome(a[i]))
    	    {
    	        return false;
    	    }
    	}
    	
    	return true;
    	
    }
};
