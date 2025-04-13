// User function Template for C++

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
  public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) 
            return NULL;
        
        unordered_map<Node*, Node*> mp;
        
        Node* new_node = new Node(node->val);
        mp[node] = new_node;
        
        queue<Node*> que;
        que.push(node);
        
        while(!que.empty()) {
            Node* curr = que.front();
            que.pop();
            
            for(auto &it : curr->neighbors) {
                if(mp.find(it) == mp.end()) {
                    mp[it] = new Node(it->val);
                    que.push(it);
                }
                
                mp[curr]->neighbors.push_back(mp[it]);
            }
        }
        
        return new_node;
    }
};
