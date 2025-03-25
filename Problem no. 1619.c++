class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();

        int remove = (n*5)/100;

        int j = n - remove;

        int sum = accumulate(arr.begin()+remove, arr.begin()+j, 0);

        return (double)sum/(j-remove);
    }
};
