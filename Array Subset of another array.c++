string isSubset(int a1[], int a2[], int n, int m) {
    sort(a1, a1+n);
    sort(a2, a2+m);
    int i=0, j=0;
    
    while(i<n && j<m)
    {
        if(a2[j]==a1[i])
        {
            a2[j] = 0;
            j++;
            i++;
        }
        
        else
        {
            i++;
        }
    }
    
    for(int k=0;k<m;k++)
    {
        if(a2[k]!=0)
            return "No";
    }
    
    return "Yes";
}
