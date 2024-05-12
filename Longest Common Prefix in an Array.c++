class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string ans="";
        // your code here
        for(int i=0;i<arr[0].length();i++){
            
            char ch=arr[0][i];
            int flag=0;
            
            for(int j=1;j<N;j++){
                
                if(ch!=arr[j][i]){
                    flag=1;
                    break;
                }
            }
            
            if(flag==0)
            ans.push_back(ch);
            
            else
            break;
        }
        
        if(ans.size()==0){
            return "-1";
        }
        
        return ans;

        
    }
};
