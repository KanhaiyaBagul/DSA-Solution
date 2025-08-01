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

    //reverse the right sub ll
    ListNode * reverse(ListNode*right){
        ListNode * curr = right;
        ListNode * prev = nullptr;
        ListNode * next = nullptr;

        while(curr != nullptr){
            next = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    //divide the ll
    ListNode *getMid(ListNode* head){
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * prev = nullptr;

        while(fast != nullptr && fast -> next != nullptr){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;

        }
         // Break the list into two halves only if prev is not nullptr
        if (prev != nullptr) {
            prev->next = nullptr;
        }

        return slow;
    }
    void reorderList(ListNode* head) {

        ListNode * leftHead = head;
        ListNode * rightHead = getMid(head);

        ListNode * rightreverse = reverse(rightHead);
        ListNode * tail = rightreverse;


        //This is the core logic of merging the two ll
        while(leftHead != nullptr && rightreverse != nullptr){
            //we created two pointers which points the next of the current left and the right it because if update the node position the connection between the next node is disconected and we don't have the access of them 
            ListNode * nextLeft = leftHead -> next;
            ListNode* nextRight = rightreverse -> next;


            //left node point the right 
            leftHead -> next = rightreverse;
            //right points to the next element of the left
            rightreverse -> next = nextLeft;

            tail = rightreverse;

            //we update our nodes to continue our process
            leftHead = nextLeft;
            rightreverse = nextRight;

        }

        if(rightreverse != nullptr){
            tail -> next = rightreverse;
        }

        return;

        
    }
};