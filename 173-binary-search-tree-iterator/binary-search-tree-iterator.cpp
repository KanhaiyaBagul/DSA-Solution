/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int>inorder;
    int i = 0;
    void dfs(TreeNode*root, vector<int>& inorder){
        if(root == nullptr){
            return;
        }

        dfs(root -> left, inorder);
        inorder.push_back(root -> val);
        dfs(root -> right, inorder);
    }
    BSTIterator(TreeNode* root) {
        if(root){
            dfs(root , inorder);
        }
        
    }
    
    int next() {
        int ans = inorder[i];
        i++;
        return ans;
        
    }
    
    bool hasNext() {
        return i < inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */