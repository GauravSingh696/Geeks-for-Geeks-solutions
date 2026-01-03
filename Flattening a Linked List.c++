/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    void bottomTrav(Node* root, vector<int> &v){
        while(root!=NULL) {
            v.push_back(root->data);
            root = root->bottom;
        }
    }
  
    Node *flatten(Node *root) {
        // code here
        vector<int> node;
        while(root!=NULL){
            node.push_back(root->data);
            if(root->bottom) bottomTrav(root->bottom, node);
            root = root->next;
        }
        
        sort(node.begin(), node.end());
        
        Node* head = new Node(node[0]);
        Node* curr = head;
        
        for(int i = 1; i < node.size(); i++){
            Node* ptr = new Node(node[i]);
            curr->bottom = ptr;
            curr = ptr;
        }
        return head;
    }
};
