class Solution
{
    public:
        void Rearrange(int arr[], int N)
        {
            // Your code goes here
            vector<int> p,n;
            for(int i=0 ; i<N ; i++){
                if(arr[i]>=0){
                    p.push_back(arr[i]);
                }
                
                else{
                    n.push_back(arr[i]);
                }
            }
            int i=0;
            
            for(auto it:n){
                arr[i++]=it;
            }
            
            for(auto it:p){
                arr[i++]=it;
            }
        }
};
