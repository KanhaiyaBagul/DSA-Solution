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
    TreeNode*arrange(int l,int r, vector<TreeNode*>& sorted){
        if(l > r) return nullptr;

        int mid = l +  (r-l) / 2;

        TreeNode* root = sorted[mid];

        root -> left = arrange(l,mid - 1, sorted);
        root -> right = arrange(mid + 1 , r,sorted);
        return root;


    }
    void dfs(TreeNode* root , vector<TreeNode*> &sorted){
        if(!root) return;

        dfs(root -> left, sorted);
        sorted.push_back(root);
        dfs(root -> right,sorted);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> sorted;
        dfs(root, sorted);
        int r = sorted.size() - 1;

        return arrange(0,r,sorted);



        
    }
};