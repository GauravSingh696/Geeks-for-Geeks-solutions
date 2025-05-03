// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    bool isPrime(int n) {
        if (n <= 1) return
            false;
        
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        
        return true;
    }
  
    Node *primeList(Node *head) {
        vector<bool> prime(10008, false);
        
        for(int i=0;i<10008;i++) {
            if(isPrime(i+1))
                prime[i] = true;
        }
        
        Node* temp = head;
        
        while(temp) {
            int val = temp->val;
            
            if(!prime[val-1]) {
                int v1 = val-1;
                
                for(;v1>=1;v1--) {
                    if(prime[v1-1])
                        break;
                }
                
                int v2 = val+1;
                
                for(;v2<10008;v2++) {
                    if(prime[v2-1])
                        break;
                }
                
                if(v1 == 0)
                    temp->val = v2;
                    
                else if(val-v1 == v2-val)
                    temp->val = v1;
                
                else if(val-v1 < v2-val)
                    temp->val = v1;
                
                else
                    temp->val = v2;
            }
            
            temp = temp->next;
        }
        
        return head;
    }
};
