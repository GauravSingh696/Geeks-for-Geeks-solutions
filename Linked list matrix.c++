// 09-10-2024

/*
struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // code Here
        vector<vector<Node*>> mt;
        int n = mat.size();
        for(int i=0; i<n; i++){
            vector<Node*> tp;
            for(int j=0; j<n; j++){
                Node* temp = new Node(mat[i][j]);
                tp.push_back(temp);
            }
            mt.push_back(tp);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((j+1) == n)
                    mt[i][j]->right = NULL;
                else
                    mt[i][j]->right = mt[i][j+1];
                if((i+1)==n)
                    mt[i][j]->down = NULL;
                else                
                    mt[i][j]->down = mt[i+1][j];
            }
        }
        return mt[0][0];
    }
};
