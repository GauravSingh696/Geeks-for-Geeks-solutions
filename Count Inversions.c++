class Solution {
  public:
    int merge(vector<int> &arr, int st, int end, int mid) {
        vector<int> temp;
        int i=st, j=mid+1;
        int invCount = 0;
        
        while(i<=mid && j<=end) {
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
                invCount += mid - i + 1;
            }
        }
        
        while(i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j <= end) {
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int idx=0;idx<temp.size();idx++) {
            arr[idx+st] = temp[idx];
        }
        
        return invCount;
    }
  
    int mergeSortCount(vector<int> &arr, int i, int j) {
        if(i < j) {
            int mid = i + (j-i)/2;
            int leftInvCount  = mergeSortCount(arr, i, mid);
            int rightInvCount = mergeSortCount(arr, mid+1, j);
            
            int InvCount = merge(arr, i, j, mid);
            
            return leftInvCount + rightInvCount + InvCount;
        }
        
        return 0;
    }
  
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        
        return mergeSortCount(arr, 0, n-1);
    }
};
