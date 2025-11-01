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
        unordered_map<int, int> elements;
        for(int num : nums){
            elements[num] = 1;
        }

        ListNode dummy;
        ListNode* temp = &dummy;

        while(head != nullptr){

            if(!elements.count(head -> val)){
                ListNode* l = new ListNode(head -> val);
                temp -> next = l;
                temp = temp -> next;
            }
            head = head -> next;
        }

        return dummy.next;

        

        
    }
};