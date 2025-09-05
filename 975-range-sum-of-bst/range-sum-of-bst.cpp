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
    void Range(TreeNode* root, int low, int high , int& result){
        if(root == nullptr){
            return;
        }

        if(root -> val >= low && root -> val <= high){
            result += root -> val;
            Range(root -> left , low , high, result);
            Range(root -> right , low , high, result);
        }
        else if(root -> val < low){
            Range(root -> right , low , high, result);
        }else{
            Range(root -> left , low , high, result);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int result = 0;
        Range(root, low , high, result);
        return result;
        
    }
};