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

    TreeNode* sortedBST(vector<int>& nums, int start , int end){
        if(start > end){
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* curr = new TreeNode(nums[mid]);

        curr -> left = sortedBST(nums, start , mid - 1);
        curr -> right = sortedBST(nums, mid  + 1 , end);

        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start = 0;
        int end = nums.size() - 1;

        return sortedBST(nums, start , end);

        
    }
};