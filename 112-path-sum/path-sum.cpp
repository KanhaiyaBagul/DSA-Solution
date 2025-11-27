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
    bool helper(TreeNode* root, int target,int sum){
        if(root == nullptr){
            return false;
        }


        sum += root -> val;
        if(!root -> left && !root -> right){
            return sum == target;
        }

        bool left = helper(root -> left, target, sum);
        bool right = helper(root -> right, target, sum);
        return (left || right);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return helper(root, targetSum , 0);
        
    }
};