struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node *d = new Node(-1);
        Node *node1 = head1 , *node2 = head2 , *nxt = d;
        
        while(node1 && node2) {
            if(node1->data <= node2->data) {
                nxt->next = node1;
                nxt =node1;
                node1 = node1->next;
            }
            
            else {
                nxt->next = node2;
                nxt = node2;
                node2 = node2->next;
            }
        }
        
        while(node1) {
            nxt->next = node1;
            nxt = node1;
            node1 = node1->next;
        }
        
        while(node2) {
            nxt->next = node2;
            nxt = node2;
            node2 = node2->next;
        }
        
        return d->next;
    }
};
