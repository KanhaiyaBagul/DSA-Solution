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
    bool isPalindrome(ListNode* head) {
        stack<int> s;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            s.push(slow -> val);
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        if(fast != nullptr){//if fast is not null means list is even then skip the middle element
            slow = slow -> next;
        }
    
        while(!s.empty()){
            if(s.top() == slow -> val){
                s.pop();
                slow = slow -> next;
            }
            else{
                return false;
            }

        }

        return true;

        
    }
};