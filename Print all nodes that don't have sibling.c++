// 06-05-2024

void solve(Node *root, vector<int> &v)
{
    if(root)
    {
        if(root->left && !root->right)
            v.push_back(root->left->data);
        
        if(!root->left && root->right)
            v.push_back(root->right->data);
        
        solve(root->left, v);
        solve(root->right, v);
        
        return ;
    }
}

vector<int> noSibling(Node* node)
{
    // code here
    vector<int> result;
    
    solve(node, result);
    
    if(result.empty())
    {
        result.push_back(-1);
    }
    
    sort(result.begin(), result.end());
    
    return result;
}
