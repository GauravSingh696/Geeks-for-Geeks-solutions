//  29-08-2024

class Solution {
  public:
    int solve(Node *head)
    {
        int count = 1;
        
        if(head == NULL)
            return 0;
        
        Node *slow = head;
        Node *fast = head;
        
        while(slow!=NULL && fast!=NULL)
        {
            fast = fast->next;
            
            if(fast != NULL)
                fast = fast->next;
            
            slow = slow->next;
            
            if(slow == fast)
            {
                while(slow->next != fast)
                {
                    slow = slow->next;
                    count++;
                }
                return count;
            }
        }
        
        return 0;
    }
  
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        
        if(head->next == NULL)
            return 0;
        
        int result = solve(head);
        
        return result;
        
    }
};
