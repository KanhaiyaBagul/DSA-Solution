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
    void inOrder(TreeNode* root, vector<int>& inorder){
        if(!root){
            return;
        }

        inOrder(root -> left,inorder);
        inorder.push_back(root -> val);
        inOrder(root -> right,inorder);
    }

    void check(TreeNode* root , int& i,vector<int>& inorder){
        if(!root) return;

        check(root -> left,i,inorder);
        
            root -> val = inorder[i];
            i++;
        
        check(root -> right,i,inorder);
    }

    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        inOrder(root, inorder);
        sort(inorder.begin(),inorder.end());
        int i = 0;
        check(root, i,inorder);

        return;  
    }
};