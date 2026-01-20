class Solution {
  public:
    string result;
    vector<char> vec;
    
    void append(char x) {
        // append x into document
        result.push_back(x);
    }

    void undo() {
        // undo last change
        vec.push_back(result.back());
        result.pop_back();
    }

    void redo() {
        // redo changes
        result.push_back(vec.back());
        vec.pop_back();
    }

    string read() {
        // read the document
        return result;
    }
};
