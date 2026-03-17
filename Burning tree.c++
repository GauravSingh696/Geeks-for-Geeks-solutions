/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Approach 1st...
class Solution {
  public:
    int minTime(Node* root, int target) {
        unordered_map<int, vector<int>> mp;
        queue<Node*> que;
        que.push(root);
        
        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                Node* node = que.front();
                que.pop();
                
                if(node->left) {
                    que.push(node->left);
                    mp[node->left->data].push_back(node->data);
                    mp[node->data].push_back(node->left->data);
                }
                
                if(node->right) {
                    que.push(node->right);
                    mp[node->right->data].push_back(node->data);
                    mp[node->data].push_back(node->right->data);
                }
            }
        }
        
        queue<int> q;
        q.push(target);
        unordered_set<int> visited;
        int steps = -1;
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                int val = q.front();
                q.pop();
                
                visited.insert(val);
                
                for(auto it : mp[val]) {
                    if(visited.find(it) == visited.end())
                        q.push(it);
                }
            }
            
            steps++;
        }
        
        return steps;
    }
};


// Approach 2nd...
class Solution {
  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        queue<Node*> que;
        que.push(root);
        
        Node* tar;
        parent[root] = NULL;
        
        while(!que.empty()) {
            Node* curr = que.front();
            que.pop();
            
            if(curr->data == target)
                tar = curr;
            
            if(curr->left) {
                que.push(curr->left);
                parent[curr->left] = curr;
            }
            
            if(curr->right) {
                que.push(curr->right);
                parent[curr->right] = curr;
            }
        }
        
        unordered_map<Node*, bool> visited;
        int t = -1;
        
        que.push(tar);
        
        while(!que.empty()) {
            int n = que.size();
            
            while(n--) {
                Node* curr = que.front();
                que.pop();
                
                visited[curr] = true;
                
                if(curr->left && !visited[curr->left]) {
                    que.push(curr->left);
                }
                
                if(curr->right && !visited[curr->right]) {
                    que.push(curr->right);
                }
                
                if(parent[curr] && !visited[parent[curr]]) {
                    que.push(parent[curr]);
                }
            }
            
            t++;
        }
        
        return t;
    }
};
