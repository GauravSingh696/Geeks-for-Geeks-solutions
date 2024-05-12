class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int, int> freqMap;
        int count = 0;

        for (int i = 0; i < n; ++i)
        {
            freqMap[arr[i]]++;
        }
        
        for (int i = 0; i < n; ++i)
        {
            int complement = k - arr[i];
            count += freqMap[complement];
            
            if (arr[i] == complement) {
                count--;
            }
        }

        return count / 2;
        
    }
};
