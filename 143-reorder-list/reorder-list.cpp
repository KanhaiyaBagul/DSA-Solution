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
    //reverse fun
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(curr != nullptr){
            next = curr -> next;
            curr -> next = prev;
            
            prev = curr;
            curr = next;

        }
        return prev;
    }
    //calculat the mid
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast != nullptr && fast -> next != nullptr){
            prev = slow;//it store the previous of slow , so we can break the first half 
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(prev != nullptr){
            prev -> next = nullptr;//so it break the list into half
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        //in this problem we divive it into 3 steps
        //step 1 : divide the whole LL into half
        //step 2 : reverse the right half
        //step 3 : merget the two LL

        ListNode* left = head;//this is the head of the left LL
        ListNode* right = getMid(head);//find the mid of other LL

        ListNode* reverseRight = reverse(right);//Reverse it

        ListNode* tail = reverseRight;//this is use when we have diff size of the LL
        while(left != nullptr && reverseRight != nullptr){
            //first we store the next element of the each LL 
            ListNode* leftNext = left -> next;
            ListNode* rightNext = reverseRight -> next;

            //point left next to the reverse right
            left -> next = reverseRight;
            //point the reverse to the next element of the left LL
            reverseRight -> next = leftNext;

            tail = reverseRight;// the tail is alway the reverseRight
            //update the value of the nodes to the next of each
            left = leftNext;
            reverseRight = rightNext;
        }
        if(tail != nullptr){//if the tail is not null means some elemente are still remaining
            //so attach the remainig to the tail
            tail -> next = reverseRight;
        }
        return;    
    }
};