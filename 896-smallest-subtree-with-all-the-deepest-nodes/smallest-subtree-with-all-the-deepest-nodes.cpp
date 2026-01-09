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
    unordered_map<int,int> m;
    int maxD = 0;
    void calcDepth(TreeNode* root , int d){
        if(!root) return;

        m[root -> val] = d;
        maxD = max(maxD , d);

        calcDepth(root -> left , d + 1);
        calcDepth(root -> right, d + 1);

    }

    TreeNode* LCA(TreeNode* root){
        if(!root || m[root -> val] == maxD){
            return root;
        }

        TreeNode* left = LCA(root -> left);
        TreeNode* right = LCA(root -> right);

        if(left && right) return root;

        return left == nullptr ? right : left;
    }


    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        calcDepth(root,0);
        return LCA(root);
        
    }
};