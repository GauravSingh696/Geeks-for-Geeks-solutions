//  20-05-2024

class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int m)
		{
		    // Code here
		    x = x%m;
		    
		    if(n==0)
		        return 1;
		       
		    if(n%2 == 0)
		        return PowMod(x*x, n/2, m);
		    
		    else
		        return (x*PowMod(x, n-1, m) % m);
		}
};
