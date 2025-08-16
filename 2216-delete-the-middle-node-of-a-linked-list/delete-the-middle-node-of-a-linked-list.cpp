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
    ListNode* deleteMiddle(ListNode* head) {

        ListNode * point = head;
        int count = 0;
        while(point != nullptr){
            point = point -> next;
            count++;
        }

        if(count < 2){
            return nullptr;
        }



        ListNode * temp = head;
        ListNode * slow =  temp;
        ListNode * fast = temp;
        ListNode * prev = nullptr;

        while(fast != nullptr && fast -> next != nullptr){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        prev -> next = slow -> next;
        return head;
        
    }
};