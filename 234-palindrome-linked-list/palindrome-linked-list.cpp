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
      stack<int> st;

      ListNode *temp = head;
        //store element in the stack
      while(temp != nullptr){
        st.push(temp->val);
        temp = temp->next;
      }

        //check if the the stack element and the stack element are equal 
      ListNode * curr = head;
      while(curr != nullptr){
        if(curr->val != st.top()){
            return false;//if not equal if not then return the false
        }
        st.pop();//remove element from stack if the the values in the ll and the stack are equla 
        curr = curr->next;

      }
      return true;  
        
    }
};