/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, vector<int> &vec) {
        if(root) {
            solve(root->left, vec);
            vec.push_back(root->data);
            solve(root->right, vec);
        }
    }
  
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> vec;
        
        solve(root, vec);
        
        return vec;
    }
};
