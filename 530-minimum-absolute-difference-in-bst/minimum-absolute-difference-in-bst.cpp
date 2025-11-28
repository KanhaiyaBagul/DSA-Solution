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
    void dfs(TreeNode* root,vector<int>&preorder){
        if(root == nullptr){
            return;
        }

        dfs(root -> left,preorder);

        preorder.push_back(root -> val);

        dfs(root -> right, preorder);

    }
    int getMinimumDifference(TreeNode* root) {

        vector<int>preorder;
        dfs(root, preorder);
        int minAbs = INT_MAX;
        for(int i = 1; i < preorder.size();i++){
            minAbs = min(minAbs, abs(preorder[i-1]- preorder[i]));

        }
        return minAbs;
    }
};