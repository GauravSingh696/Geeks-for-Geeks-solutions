/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int solve(Node* root, int &move, int &balance) {
        if(!root)
            return 0;
        
        balance += root->data-1;
        root->data += (solve(root->left, move, balance) + solve(root->right, move, balance));
        
        if(root->data <= 0) {
            move += (root->data - 1) * (-1);
        } else {
            move += root->data - 1;
        }
        
        return root->data - 1;
    }
  
    int distCandy(Node* root) {
        int move = 0, balance = 0;
        
        solve(root, move, balance);
        
        return move;
    }
};
