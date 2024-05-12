// 12-05-2024

class Solution {
  public:
    int minSteps(int d) {
        // code here
        int sum=0, count=1;
        
        while(1)
        {
            sum += count;
            count++;
            
            if(sum == d)
            {
                count--;
                break;
            }
            
            if(sum > d)
            {
                if((sum-d)%2==0)
                {
                    count--;
                    break;
                }
            }
        }
        
        return count;
        
    }
};
