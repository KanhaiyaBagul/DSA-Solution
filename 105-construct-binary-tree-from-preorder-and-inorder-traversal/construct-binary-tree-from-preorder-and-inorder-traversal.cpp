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
    TreeNode* helper(int start,int end,int& idx,vector<int>& preorder, vector<int>& inorder){
        if(start > end){
            return nullptr;
        }
        int rootVal = preorder[idx];//first find the root node
        
        int i = start;//this is the index of the root node present in the preorder
        for(;i <= end; i++){//here we find the index of root node in the preorder
            if(inorder[i] == rootVal){
                break;
            }
        }
        idx++;//increment the idx

        TreeNode* root = new TreeNode(rootVal);//create a new node

        root -> left = helper(start, i - 1, idx, preorder, inorder);
        root -> right = helper(i + 1,end, idx, preorder, inorder);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return helper(0,n-1,idx, preorder, inorder);
           
    }
};