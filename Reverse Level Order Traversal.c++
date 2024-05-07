// 07-05-2024

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> result;
    queue<Node *> q;
    stack<int> st;
    
    q.push(root);
    
    while(!q.empty())
    {
        Node *node = q.front();
        q.pop();
        
        st.push(node->data);
        
        if(node->right)
        {
            q.push(node->right);
        }
        
        if(node->left)
        {
            q.push(node->left);
        }
    }
    
    while(!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
}
