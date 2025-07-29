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

    
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //first we have to calculate the size of the ll
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }

        if(n == size){
            return head->next;
        }

        //This is for removing the nth node from the last
        ListNode*prev = head;//start from the head

        //Get to the previoius node of the Nth element  
        for(int i = 1; i < (size - n); i++){
            prev = prev->next;
        }
        //point toward prev-> next to the prev->next->next element
        prev->next = prev->next->next;
        return head;
    }
};