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
    long long maxPro = LLONG_MIN;
    const int MOD = 1e9 + 7;

    long long sumTree(TreeNode* root){
        if(!root) return 0;
        return root -> val + sumTree(root -> left) + sumTree(root -> right);
    }

    long long dfs(TreeNode* root,long long totalSum){
        if(!root) return 0;

        long long left = dfs(root -> left , totalSum);
        long long right = dfs(root -> right, totalSum);

        long long subTree = root -> val + left + right;

        maxPro = max(maxPro, subTree * (totalSum - subTree));
        return subTree;
    }
    int maxProduct(TreeNode* root) {

        long long totalSum = sumTree(root);
        dfs(root,totalSum);
        return maxPro % MOD;

        
    }
};