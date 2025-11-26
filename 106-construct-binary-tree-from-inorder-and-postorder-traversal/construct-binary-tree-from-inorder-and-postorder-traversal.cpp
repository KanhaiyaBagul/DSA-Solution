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
    TreeNode* helper(int start, int end, int& idx,vector<int>& inorder, vector<int>& postorder){
        if(start > end){
            return nullptr;
        }

        int rootValue = postorder[idx];
        int i = start;
        for(;i <= end;i++){
            if(inorder[i] == rootValue){
                break;
            }
        }

        idx--;

        TreeNode* root = new TreeNode(rootValue);

        root -> right = helper(i + 1 , end, idx, inorder, postorder);
        root -> left = helper(start , i - 1, idx, inorder, postorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n - 1;

       return helper(0,n-1,idx,inorder, postorder);
        
        
    }
};