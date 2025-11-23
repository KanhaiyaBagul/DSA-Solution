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

    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int right = 1 + height(root -> right);
        int left = 1 + height(root -> left);

        return max(right, left);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int left = height(root -> left);
        int right = height(root -> right);
        
        if(abs(left - right) > 1) return false;


        bool l = isBalanced(root -> left);
        bool r = isBalanced(root -> right);

        if(!r || !l) return false;
        return true;

    }
};