class Solution {
  public:
    vector<pair<int, int>> vec;
    int min_val = INT_MAX;
    
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        vec.push_back({x, min_val});
        min_val = min(min_val, x);
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!vec.empty()) {
            min_val = vec.back().second;
            vec.pop_back();
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(vec.empty())
            return -1;
            
        return vec.back().first;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        return vec.empty() ? -1 : min_val ;
    }
};
