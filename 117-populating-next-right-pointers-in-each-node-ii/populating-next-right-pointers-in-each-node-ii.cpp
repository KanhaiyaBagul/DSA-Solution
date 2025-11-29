/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* dfs(queue<Node*>&q, int &i ,int n){
        if(i == n){
            return nullptr;
        }

        Node* curr = q.front();
        i++;
        q.pop();

        if(curr -> left){
            q.push(curr -> left);
        }
        if(curr -> right){
            q.push(curr -> right);
        }

        curr -> next = dfs(q, i, n);
        return curr;  
    }
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int i = 0;
            dfs(q,i,size);
        }
        return root;
    }

};