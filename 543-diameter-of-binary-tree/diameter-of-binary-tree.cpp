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
    pair<int ,int > diameter(TreeNode* root){
        if(root == nullptr){
            return make_pair(0,0);
        }   
        //Diameter , height
        pair<int , int > leftD = diameter(root -> left);
        pair<int , int> rightD = diameter(root -> right);

        int currD = leftD.second + rightD.second;
        int finalD = max({currD , leftD.first, rightD.first});

        int finalHt = max(leftD.second , rightD.second) + 1;
        return make_pair(finalD, finalHt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        return diameter(root).first;
    }
};