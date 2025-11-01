/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        //store the nums in the set
        unordered_set<int> s(nums.begin(),nums.end());
        

        ListNode dummy;//create a dummy node
        ListNode* temp = &dummy;//create new ListNode and it is pointing to the address of the dummy node

        while(head != nullptr){

            if(s.find(head -> val) == s.end()){//if the node is not present in the set the add to the new list node
                ListNode* l = new ListNode(head -> val);
                temp -> next = l;//point the new node to the list
                temp = temp -> next;//move forward the temp
            }
            head = head -> next;//also move the head pointer  , which is use for traversel
        }

        return dummy.next;//this return the starting node of our resultent 

        

        
    }
};