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
    void DFS(TreeNode* root,string& str){
        if(root == nullptr){
            str+="#";
            return;
        }

        str +=(to_string(root -> val));

        DFS(root -> right,str);
        DFS(root -> left ,str);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string str1 = "";
        string str2 = "";

        DFS(p,str1);
        DFS(q,str2);

        return str1 == str2;

        
        
    }
};