class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> leaves;
        int index = 0;
        
        findLeaves(preorder, index, INT_MIN, INT_MAX, leaves);
        
        return leaves;
    }

  private:
    void findLeaves(vector<int>& preorder, int& index, int minVal, int maxVal, vector<int>& leaves) {
        if (index >= preorder.size())
            return;

        int val = preorder[index];
        
        if (val < minVal || val > maxVal)
            return;

        index++;
        int currIndex = index;

        // Recursively process left subtree
        findLeaves(preorder, index, minVal, val - 1, leaves);
        
        // Recursively process right subtree
        findLeaves(preorder, index, val + 1, maxVal, leaves);

        // If index hasn't changed from currIndex, this node has no children => leaf
        if (index == currIndex)
            leaves.push_back(val);
    }
};
