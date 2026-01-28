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
    //so their is only two numbers , we just have to track them in the recursion 
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    void inOrder(TreeNode* root){
        if(!root){
            return;
        }

        inOrder(root -> left);
        if(prev && prev -> val > root -> val){
            //if we don't find the first element , so the this could be the first and prev is the the node for the first
            if(!first){
                first = prev;
            }
            //for the second element when it hit the prev > root
            //so the root is the second element
            second = root;
        }
        prev = root;
        inOrder(root -> right);
    }



    void recoverTree(TreeNode* root) {
        
        inOrder(root);
        swap(first-> val,second->val);
        return;  
    }
};