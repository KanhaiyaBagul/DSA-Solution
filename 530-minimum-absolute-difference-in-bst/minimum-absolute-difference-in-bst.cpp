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
    void dfs(TreeNode* root,vector<int>&inorder){
        if(root == nullptr){
            return;
        }

        dfs(root -> left,inorder);

        inorder.push_back(root -> val);

        dfs(root -> right, inorder);

    }
    int getMinimumDifference(TreeNode* root) {

        vector<int>inorder;
        dfs(root, inorder);
        int minAbs = INT_MAX;
        for(int i = 1; i < inorder.size();i++){
            minAbs = min(minAbs, abs(inorder[i-1]- inorder[i]));

        }
        return minAbs;
    }
};