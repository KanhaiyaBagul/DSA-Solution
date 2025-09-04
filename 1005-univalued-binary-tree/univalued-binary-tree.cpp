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

    bool True(TreeNode* root, int n){
        if(root == nullptr){
            return true;
        }
        if(root -> val != n){
            return false;
        }

        return True(root -> left , n) && True(root -> right , n);

    }
    bool isUnivalTree(TreeNode* root) {
        return True(root, root -> val); 
    }
};