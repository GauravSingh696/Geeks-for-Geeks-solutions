// 15-07-2024

class Solution {
  public:
    string smallestNumber(int s, int d) {
        
        int num = pow(10, d-1);
        
        for(int i=num;i<num*10;i++)
        {
            int n = i;
            int sum = 0;
            
            while(n)
            {
                sum += n%10;
                n /= 10;
            }
            
            if(sum == s)
                return to_string(i);
        }
        
        return "-1";
        
    }
};
