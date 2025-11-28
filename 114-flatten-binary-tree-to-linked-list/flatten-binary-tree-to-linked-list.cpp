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

    void revpre(TreeNode* root,stack<TreeNode*>& s){
        if(root == nullptr){
            return;
        }
        
        revpre(root -> right,s);

        revpre(root -> left,s);

        s.push(root);

        
        
    }
    void flatten(TreeNode* root) {
        stack<TreeNode*>s;
        revpre(root,s); // reverser pre order

        recursion(s);//this assembles the node in give condition

        
    }
};