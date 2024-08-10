// 10-08-2024

class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        if(head == NULL)
            return head;
        
        Node* newnode = head;
        int n = k;
        
        Node* count = head;
        int c = 0;
        
        while(count)
        {
            count = count->next;
            c++;
        }
        
        if(c <= k)
            return head;
        
        while(head && n--)
        {
            head = head->next;
        }
        
        Node* result = new Node(head->data);
        Node* curr = result;
        head = head->next;
        
        while(head)
        {
            curr->next = new Node(head->data);
            curr = curr->next;
            head = head->next;
        }
        
        while(newnode && k--)
        {
            curr->next = new Node(newnode->data);
            curr = curr->next;
            newnode = newnode->next;
        }
        
        return result;
        
    }
};
