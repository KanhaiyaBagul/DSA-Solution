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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* temp = head;
        while(temp != nullptr && temp -> next != nullptr){
            //it the next val is matching then point to the next of the duplicate
            if(temp -> val == temp -> next -> val){
                temp -> next = temp -> next -> next;
            }else{
                temp = temp -> next;
            }
        }

        return head;
        
    }
};