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
    ListNode* reverseList(ListNode* head) {
        ListNode*prev = NULL; //when we start form the first node it's previous initialize to NULL
        ListNode*curr = head;//we start from the current node so we initialize with the head

        //we run the loop until we get curr to the null
        while(curr != NULL){
            ListNode*next = curr->next;//save the next node before breaking

            //REverse the currnt node's pointer
            curr-> next  = prev;

            //Move prev and curr one step forward
            prev = curr;
            curr = next;
        }
        //prev noe points to the new head of the reversed list
       return prev;
        
    }
};