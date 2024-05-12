class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    
	    queue<int> q1;
	    queue<int> q2;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	        {
	            q2.push(arr[i]);
	        }
	        else
	        {
	            q1.push(arr[i]);
	        }
	    }
	    
	    int s1 = q1.size();
	    int s2 = q2.size();
	    queue<int> que;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(i%2==0)
	        {
	            if(q2.empty())
	                break;
	            que.push(q2.front());
	            q2.pop();
	        }
	        
	        else
	        {
	            if(q1.empty())
	                break;
	           
	            que.push(q1.front());
	            q1.pop();
	        }
	    }
	    
	    while(!q1.empty())
	    {
	        que.push(q1.front());
	        q1.pop();
	    }
	    
	    while(!q2.empty())
	    {
	        que.push(q2.front());
	        q2.pop();
	    }
	    
	    
	    for(int i=0;i<n;i++)
	    {
	        arr[i] = que.front();
	        que.pop();
	    }
	    
	}
};
