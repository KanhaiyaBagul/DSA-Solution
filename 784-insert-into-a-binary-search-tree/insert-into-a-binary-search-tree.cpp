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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //if the root is null
        if(root == nullptr){
            root =  new TreeNode(val);
            return root;
        }

        //if val is less than the root
        if(val < root -> val){
            root -> left = insertIntoBST(root -> left, val);
        }else{
            root -> right = insertIntoBST(root -> right , val);
        }

        //it returns the current node were we are present
        return root;
        
    }
};