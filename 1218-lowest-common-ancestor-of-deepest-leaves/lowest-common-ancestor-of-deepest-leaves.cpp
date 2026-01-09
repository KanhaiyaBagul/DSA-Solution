/*
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
    int maxDep = 0;

    TreeNode* LCA(TreeNode* root){
        //if the node is the depest leaf node then return that node
        if(!root || m[root -> val] == maxDep){
            return root;
        }

        TreeNode* left = LCA(root -> left);
        TreeNode* right = LCA(root -> right);

        if(left && right) return root;

        return left == nullptr ? right : left;
    }

    //calculate the depth of each node and store in it Hash Map
    void calcDepth(TreeNode*root,int d){

        if(!root) return;

        m[root -> val] = d;
        maxDep = max(maxDep,d);
        calcDepth(root -> left,d + 1);
        calcDepth(root -> right,d + 1);       
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        calcDepth(root, 0);
        return LCA(root);

        
 
    }
};