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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        //if root is null
        if(root == nullptr){
            return {};
        }
        //create queue for level traversal
        queue<TreeNode*> Q;
        //push root to the queue
        Q.push(root);


        while(!Q.empty()){
            //size of the queue
            int levelSize = Q.size();
            //this stores the level wise int
            vector<int> temp;

            //traverse for the only element who are in the levell
            for(int i = 0; i < levelSize; i++){
                TreeNode* curr = Q.front();
                Q.pop();
                //push every element to the temp 
                temp.push_back(curr -> val);

                if(curr -> left != nullptr){
                    Q.push(curr -> left);
                }
                if(curr -> right != nullptr){
                    Q.push(curr -> right);
                }
            }

            result.push_back(temp);
        }
        return result;

        
    }
};