// 29-06-2024

bool areIdentical(struct Node *head1, struct Node *head2) {
    // Code here
    
    while(head1 && head2)
    {
        if(head1->data == head2->data)
        {
            head1 = head1->next;
            head2 = head2->next;
        }
        
        else
            return false;
    }
    
    if((head1 && !head2) || (!head1 && head2))
        return false;
    
    return true;
    
}
