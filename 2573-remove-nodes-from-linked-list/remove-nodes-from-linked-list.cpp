/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };..
 */
class Solution {
public:

    ListNode * reverse(ListNode* head){
        ListNode * prev = nullptr;
        ListNode* curr =  head;
        ListNode* next = nullptr;

        while(curr != nullptr){
            next = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = next;
        }

        return prev;

    }
    ListNode* removeNodes(ListNode* head) {
        //gives the rev list head
        ListNode *revHead = reverse(head);
        //initialize the curr to the rev Head
        ListNode * curr = revHead;
        //store the first value as the max
        int max = curr-> val;
        //previous store the last max
        ListNode * prev = curr;
        //curr move to next
        curr = curr -> next;

        while(curr != nullptr){
            if(curr-> val >= max){
                max = curr -> val;
                prev = curr;
                curr = curr -> next;
            }else{
                prev -> next = curr -> next;
                curr = curr-> next;
            }
        }

        return reverse(revHead);
        
    }
};