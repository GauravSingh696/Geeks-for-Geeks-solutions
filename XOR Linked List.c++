// 07-10-2024

/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data) {
    // Code here
    Node *temp = new Node(data);
    temp->npx = head;
    
    return temp;
}

vector<int> getList(struct Node *head) {
    // Code here
    
    vector<int> result;
    
    while(head) {
        result.push_back(head->data);
        head = head->npx;
    }
    
    return result;
}
