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
    //traverse through the tree and get the element in string format
    void DFS(TreeNode* root,string& str){
        if(root == nullptr){
            str+="#";//this is use for where is the nullptr lie
            return;
        }

        str +=(to_string(root -> val));

        DFS(root -> left ,str);
        DFS(root -> right,str);
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string str1 = "";//store the p path
        string str2 = "";//store the q path

        DFS(p,str1);
        DFS(q,str2);

        return str1 == str2;

        
        
    }
};