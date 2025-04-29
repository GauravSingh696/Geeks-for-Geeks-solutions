/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        vector<int> cnt(3,0);
        Node *temp = head;
        
        while(temp) {
            cnt[temp->data]++;
            temp=temp->next;
        }
        
        temp = head;
        
        for(int i=0 ; i<3 ; i++) {
            while(cnt[i]) {
                temp->data = i;
                temp=temp->next;
                cnt[i]--;
            }
        }
        return head;
    }
};
