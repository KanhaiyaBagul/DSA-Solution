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

    ListNode * sortList(ListNode * left, ListNode* right){
        //it is the dummy node 
        ListNode dummy(0);
        ListNode* tail = &dummy;
        //They are the pointer 
        ListNode* i =  left;
        ListNode* j = right;

        while(i != nullptr && j != nullptr){
            if(i->val < j -> val){
               tail->next = i;//add the node after the tail
                i = i-> next;//shift the value of the node
            }else{
                tail->next = j;
                j = j -> next;
            }

            tail = tail->next;//it moves the tail
        }

        //this merge the remaining element 
        while (i != nullptr){
            tail->next = i;
            i = i -> next;
            tail = tail->next;
        }

        while (j != nullptr){
            tail->next = j;
            j = j -> next;
            tail = tail->next;
        }

        return dummy.next;  //dummy → 1 → 2 → 3 → 4
    }
    ListNode* getMid(ListNode*head){
        ListNode* slow = head;//create slow pointer
        ListNode* fast = head;//create the fast poineter

        ListNode * prev = nullptr; //This is use to make the two link list , use to initialize the left ll last tail to point to the nullptr

        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow -> next;
            fast  = fast->next->next;
        }

        prev -> next = nullptr;//We succesfully create two link list

        return slow;

    }
    ListNode* sortList(ListNode* head) {

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode * mid = getMid(head);

        ListNode* left = sortList(head);
        ListNode*right = sortList(mid);

        return sortList(left, right);
        
        
    }
};