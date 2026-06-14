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
    int pairSum(ListNode* head) {
        int maxPair = INT_MIN;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next != nullptr && fast -> next -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* mid = slow -> next;
        ListNode* curr = mid;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(curr != nullptr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* halfStart = prev;
        ListNode* i = halfStart;
        ListNode* j = head;

        while(i){
            int sum = i -> val + j -> val;
            maxPair = max(maxPair, sum);
            i = i -> next;
            j = j -> next;
        }
        return maxPair;
        
    }
};