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
    
    TreeNode* searchBST(TreeNode* root, int val) {
        //if we found the node then return
        if(root == nullptr){
            return nullptr;
        }

        //if we found the value then reutn the root node
        if(root -> val == val){
            return root;
        }


        if(val < root -> val){
            return searchBST(root -> left , val);
        }else {
            return searchBST(root -> right , val);
        }
        

        
    }
};