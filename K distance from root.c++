// 03-05-2024

class Solution
{
    public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
      // Your code here
        vector<int> result;
        queue<Node *> que;
        que.push(root);
        
        int level = 0;
        
        while(!que.empty())
        {
            int n = que.size();
            
            for(int i=0;i<n;i++)
            {
                Node *temp = que.front();
                que.pop();
                
                if(level == k)
                {
                    result.push_back(temp->data);
                }
                
                if(temp->left)
                    que.push(temp->left);
                
                if(temp->right)
                    que.push(temp->right);
            }
            
            level++;
        }
        
        return result;
    }
};
