class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int n = a.size(), m = b.size();
        vector<int> res;

        while (i < n && j < m) {
            if (a[i] < b[j]) {
                if (res.empty() || res.back() != a[i])
                    res.push_back(a[i]);
                i++;
            }
            else if (a[i] > b[j]) {
                if (res.empty() || res.back() != b[j])
                    res.push_back(b[j]);
                j++;
            }
            else { // equal
                if (res.empty() || res.back() != a[i])
                    res.push_back(a[i]);
                i++;
                j++;
            }
        }

        while (i < n) {
            if (res.empty() || res.back() != a[i])
                res.push_back(a[i]);
            i++;
        }

        while (j < m) {
            if (res.empty() || res.back() != b[j])
                res.push_back(b[j]);
            j++;
        }

        return res;
    }
};
