class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int result = 0 , n = arr.size();
        
        for (int i = 0; i < n - 2; i++) {
            int low = i + 1, high = n - 1;
            while (low < high) {
                int sum = arr[i] + arr[low] + arr[high];
                if (sum == target) {
                    result++;
                
                    int tempLow = low + 1;
                    int tempHigh = high - 1;

                    while (tempLow < high && arr[tempLow] == arr[low]) {
                        result++;
                        tempLow++;
                    }
                    while (tempHigh > low && arr[tempHigh] == arr[high]) {
                        result++;
                        tempHigh--;
                    }

                    low++;
                    high--;
                }
                else if (sum < target) {
                    low++; 
                }
                else {
                    high--; 
                }
            }
        }

        return result;
    }
};
