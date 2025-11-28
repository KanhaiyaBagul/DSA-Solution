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
    void dfs(TreeNode*root , string curr,int& sum){
        if(root == nullptr){
            return;
        }
        curr += to_string(root -> val);

        if(root -> right == nullptr && root -> left == nullptr){
            sum += stoi(curr);
        }

        dfs(root -> left , curr, sum);
        dfs(root -> right,curr, sum);


    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, "",sum);
        return sum;
        
        
    }
};