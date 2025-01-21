/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if(!head || !head->next) 
            return head;
            
        Node *prev = NULL;
        Node *curr = head;
        
        int i = 0;
        
        while(curr && i<k) {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        
        head->next = reverseKGroup(curr, k);
        
        return prev;
    }
};
