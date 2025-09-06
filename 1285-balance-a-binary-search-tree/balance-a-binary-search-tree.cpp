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

    TreeNode* BST(vector<int>& inorder , int start , int end){
        if(start > end){
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        TreeNode* curr = new TreeNode(inorder[mid]);

        curr -> left = BST(inorder, start , mid - 1);
        curr -> right = BST(inorder, mid + 1 , end);

        return curr;
    }
    //inorder gives the sorted array
    void getInOrder(TreeNode* root , vector<int>& inorder){
        if(root == nullptr){
            return;
        }
        
        getInOrder(root -> left , inorder);

        inorder.push_back(root -> val);

        getInOrder(root -> right , inorder);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        //calculate inorder , sorted array
        getInOrder(root , inorder);
        
        int start = 0;
        int end = inorder.size() - 1;
        return BST(inorder, start , end);
        
    }
};