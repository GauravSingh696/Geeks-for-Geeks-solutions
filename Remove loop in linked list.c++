/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        unordered_set<Node*> st;
        Node* trv = head;
        Node* prev = NULL;
        
        while(trv) {
            if(st.find(trv) != st.end()) {
                prev->next = NULL;
                break;
            }
            
            st.insert(trv);
            prev = trv;
            trv = trv->next;
        }
    }
};
