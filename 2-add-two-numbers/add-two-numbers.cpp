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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode * dummy = new ListNode(-1);//first crete a dummy node 
        ListNode * curr = dummy;//curr is pointing to the dummy node
        //This two are the pointer of the given ll
        ListNode * temp1 = l1;
        ListNode * temp2 = l2;
        //intitialize the carry to 0
        int carry = 0;

        while(temp1 != nullptr || temp2  != nullptr){
            //add carry to the sum 
            int sum = carry;

            if(temp1) sum += temp1 -> val;//it check if the temp1 is null or not and then add to the sum
            if(temp2) sum += temp2 -> val;
            //create new node 
            ListNode *newNode = new ListNode(sum % 10);

            carry = sum / 10; //generate carrry
            curr -> next = newNode;//currnt point to the new node
            curr = curr-> next;//move the curr forward

            //increament the temp1 and temp2
            if(temp1) temp1 = temp1 -> next;
            if(temp2) temp2 = temp2 -> next;
        }

        //if any carry is left then add to the last 
        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr -> next = newNode;
        }

        return dummy->next;//return the head 
    }
};