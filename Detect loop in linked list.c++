/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        set<Node*> temp;
        
        while(head) {
            if(temp.count(head) == 0)
                temp.insert(head);
            
            else
                return true;
            
            head = head->next;
        }
        
        return false;
    }
};
