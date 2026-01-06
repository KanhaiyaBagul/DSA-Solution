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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int ans = 1;
        int maxSum = INT_MIN;


        while(!q.empty()){
            int sum = 0;
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                sum += temp -> val;
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }

            if(sum > maxSum){
                maxSum = sum;
                ans = level;
                
            }
            level++;

        }
        return ans;
        
    }
};