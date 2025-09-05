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
    //find the inorder successor
    TreeNode* getInorderSuccessor(TreeNode* root){
        while(root -> left != nullptr){
            root = root -> left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        //if the key node is not find
        if(root == nullptr){
            return nullptr;
        }

        if(key < root -> val){
            root -> left = deleteNode(root -> left, key);
        }else if(key > root -> val){
            root -> right = deleteNode(root -> right , key);
        }else{
            //root == key
            //case 1 : 0 child
            if(root -> left == nullptr && root -> right == nullptr){
                delete root;
                return nullptr; 
            }
            //case 2: 1 child
            if(root -> left == nullptr || root -> right == nullptr){
                return root -> left == nullptr ? root -> right : root -> left;
            }

            //case 3 : 2 child
            TreeNode* IS = getInorderSuccessor(root -> right);
            //replace value of delet node with the inorder successor
            root -> val = IS -> val;
            //now delet the right value
            root -> right = deleteNode(root -> right , IS -> val);
            return root;
        }
        return root;
        
    }
};