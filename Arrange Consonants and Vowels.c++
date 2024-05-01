// 01-05-2024

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        
        queue<int> vowel, cons;
        Node *h1=head;
        
        while(h1)
        {
            if(h1->data=='a' || h1->data=='e' || h1->data=='i' || h1->data=='o' || h1->data=='u')
            {
                vowel.push(h1->data);
            }
            
            else
            {
                cons.push(h1->data);
            }
            
            h1 = h1->next;
        }
        
        h1=head;
        
        while(h1)
        {
            if(!vowel.empty())
            {
                h1->data = vowel.front();
                vowel.pop();
            }
            
            else
            {
                h1->data = cons.front();
                cons.pop();
            }
            
            h1 = h1->next;
        }
        
        return head;
    }
};
