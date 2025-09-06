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

    //helper fun
    bool Validate(TreeNode* root , TreeNode* min , TreeNode* max){
        if(root == nullptr){//base conditioin for the null ptr is is valid bst
            return true;
        }

        //their are two condition for nodes to be valid
        //1.node > max in left subtree  if any node violat this conditon it return false
        if(max != nullptr && root -> val >= max -> val){
            return false;
        }

        //2.node > min in the right substree , if any node violat this conditon it return false
        if(min != nullptr && root -> val <= min -> val){
            return false;
        }

        //both right and left value must be true
        return Validate(root -> left, min , root) && Validate(root -> right , root , max);
    }
    bool isValidBST(TreeNode* root) {
        //for the root node the value of min and max is null
        return Validate(root, nullptr , nullptr);
        
    }
};