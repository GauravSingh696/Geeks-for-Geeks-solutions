int maxSubarraySum(vector<int>& arr, int k) {
        int sum = 0;
        for(int i = 0;i<k;i++){
            sum = sum + arr[i];
        }
        int m = 0;
        int maxi = sum;
        for(int i = k;i<arr.size();i++){
            sum = sum - arr[m];
            sum = sum + arr[i];
            maxi = max(maxi,sum);
            m++;
        }
        return maxi;
    }
