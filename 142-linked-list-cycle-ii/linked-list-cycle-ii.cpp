/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode * fast = head;
        bool isCycle = false;
        //We check if the cycle is formed or not
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast){
            isCycle = true;
            break;
            }
        }

        if(!isCycle) return nullptr;//If no cycle is formed

        slow = head;//if the cycle is formed them initialize the slow to the head

        //then move the fast and slow by 1
        //There is the conditon we met both the slow and the fast at the starting point of the loop 
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }

        return slow;//return the the slow 

        
        
    }
};