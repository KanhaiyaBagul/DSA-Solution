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
    void path(TreeNode* root , string current , vector<string>& result){
        //if we go to the nullptr
        if(root == nullptr){
            return;
        }
        //if we find the leaf node
        if(root -> left == nullptr && root -> right == nullptr){
            result.push_back(current);
            return;
        }

        //if any left value present so add the left value and move forward
        if(root -> left){
            path(root -> left, current + "->" + to_string(root ->left -> val), result);
        }

        if(root -> right){
            path(root -> right, current + "->" + to_string(root ->right -> val),result);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        string current = "";
        current += to_string(root -> val);
        vector<string> result;
        path(root ,current , result);
        return result;
        
    }
};