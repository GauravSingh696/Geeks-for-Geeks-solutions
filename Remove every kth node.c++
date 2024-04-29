// 29-04-2024

class Solution {
    public:
    Node* deleteK(Node *head,int K){
      //Your code here
        
        if(K==1)
            return NULL;
            
        Node *prev=NULL, *curr=head;
        int count=0;
      
        while(curr)
        {
            count++;
            
            if(count%K == 0)
            {
                prev->next = curr->next;
                count = 0;
            }
            
            prev = curr;
            curr = curr->next;
        }
        
        return head;
      
    }
};
