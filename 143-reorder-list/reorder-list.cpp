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

        while(leftHead != nullptr && rightreverse != nullptr){

            ListNode * nextLeft = leftHead -> next;
            ListNode* nextRight = rightreverse -> next;


            leftHead -> next = rightreverse;
            rightreverse -> next = nextLeft;

            tail = rightreverse;

            leftHead = nextLeft;
            rightreverse = nextRight;

        }

        if(rightreverse != nullptr){
            tail -> next = rightreverse;
        }

        return;

        
    }
};