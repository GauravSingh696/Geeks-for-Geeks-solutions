/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto it : arr) { 
            while(it) {
                pq.push(it->data);
                it = it->next;
            }
        }
        
        Node *res = new Node(-1) , *temp=res;
        
        while(!pq.empty()) {
            temp->next = new Node(pq.top());
            temp=temp->next;
            pq.pop();
        }
        
        return res->next;

    }
};
