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
    int result = 0;

    int bfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = bfs(root -> left);
        int right = bfs(root -> right);
        result += abs(left - right);

        //for the uppar one we have to calculate the the lower one to move upward
        return root -> val + left + right;
    }
    int findTilt(TreeNode* root) {
        bfs(root);
        return result;
          
    }
};