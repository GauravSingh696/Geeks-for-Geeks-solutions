class Solution {
  public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first)
            return a.second > b.second;
            
        return a.first < b.first;
    }

    vector<int> printKClosest(vector<int> arr, int k, int x) {
        vector<pair<int,int>> temp;
        
        for(int i=0 ; i<arr.size() ; i++) {
            if(arr[i]==x)
                continue;
                
            temp.push_back( {abs(x-arr[i]) , arr[i]});
        }
        
        sort(temp.begin() , temp.end() , cmp);
        vector<int> result;
        
        for(int i=0 ; i<k ; i++) {
            result.push_back(temp[i].second);
        }
        
        return result;
    }
};

