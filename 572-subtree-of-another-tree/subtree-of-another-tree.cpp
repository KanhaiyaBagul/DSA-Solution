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
    bool helper(TreeNode* root, TreeNode* subRoot){

        if(root == nullptr && subRoot == nullptr){
            return true;
        }else if(root == nullptr || subRoot == nullptr){
            return false;
        }

        if(root -> val != subRoot -> val){
            return false;
        }

        bool left = helper(root -> left , subRoot -> left);
        bool right = helper(root -> right , subRoot -> right);
        return left && right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root  == nullptr && subRoot == nullptr){
            return true;
        }else if(root == nullptr || subRoot == nullptr){
            return false;
        }

        if(root-> val == subRoot -> val){
            if(helper(root, subRoot)){
                return true;
            }
        }

        bool left = isSubtree(root -> left, subRoot);
        bool right = isSubtree(root -> right, subRoot);

        return left || right;

        
        
    }
};