/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return{};//if root is null
        vector<vector<int>> result;//store the result
        queue<TreeNode*> q;//queue for level order traversal

        q.push(root);//initially push the root
        bool toggle = false;//use toggle for reverse the vector

        while (!q.empty()) {

            vector<int> temp;
            int n = q.size();
            //it add the curr added element in the vector and child to the queue
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();

                temp.push_back(curr->val);

                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            //it is for the reverse mode
            if(toggle){
                reverse(temp.begin(),temp.end());
            }
            result.push_back(temp);//add to the result
            toggle = !toggle;//switch the value of the toggle

        }
        return result;
    }
};