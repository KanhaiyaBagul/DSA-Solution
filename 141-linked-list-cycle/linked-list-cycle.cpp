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
    bool hasCycle(ListNode *head) {
        //Both pointer start form head
        ListNode *slow = head;
        ListNode *fast = head;

        //this is loop if the ll is circular or nor is it is then it stop
        while(fast != nullptr && fast-> next != nullptr){

            //we update our slow and the fast pointer
            slow = slow -> next;
            fast = fast->next->next;
            
            //it they meat a same positon that mean it is circular
            if(slow == fast){
                return true;
            }
        }
        return false;
        
    }
};