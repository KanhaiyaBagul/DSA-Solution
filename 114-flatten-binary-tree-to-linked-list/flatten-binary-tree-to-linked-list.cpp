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
class Solution {
public:

    TreeNode* recursion(stack<TreeNode*>&s){
        if(s.empty()){
            return nullptr;
        }

        TreeNode* curr = s.top();
        s.pop();

        curr -> right = recursion(s);
        curr -> left = nullptr;
        return curr;
    }

    void pre(TreeNode* root,stack<TreeNode*>& s){
        if(root == nullptr){
            return;
        }
        
        pre(root -> right,s);

        pre(root -> left,s);

        s.push(root);

        
        
    }
    void flatten(TreeNode* root) {
        stack<TreeNode*>s;
        pre(root,s);

        TreeNode* ans = recursion(s);

        
    }
};