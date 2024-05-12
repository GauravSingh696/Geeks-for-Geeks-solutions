class Solution{   
public:
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here
        int l=0;
        int r=array.size()-1;
        for(int i=0 ; i<=r ; i++)
        {
            if(array[i]<a)
            {
                swap(array[l] , array[i]);
                l++;
            }
            
            else if(array[i]>b)
            {
                swap(array[r] , array[i]);
                r--;
                i--;
            }
        }
    }
};
