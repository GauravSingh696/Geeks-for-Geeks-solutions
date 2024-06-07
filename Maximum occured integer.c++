// 07-06-2024

class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {
        // Your code here
        map<int,int> mp;
        for(int i=0 ; i<n ; i++)
        {
            mp[l[i]]++;
            mp[r[i] + 1]--;
        }
        
        int maxInteger = 0, maxOccurrences = 0, prefixSum = 0;
        for(auto it : mp) {
            prefixSum += it.second;
            if(prefixSum > maxOccurrences) {
                maxInteger = it.first;
                maxOccurrences = prefixSum;
            }
        }

        return maxInteger;
    }
};
