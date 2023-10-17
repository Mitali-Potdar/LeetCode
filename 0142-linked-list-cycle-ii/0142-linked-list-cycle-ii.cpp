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
        ListNode* fast = head;
        while(fast && slow && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow){
                // Reset the slow pointer to the head of the linked list, and move both pointers one step at a time
                // until they meet again. The node where they meet is the starting point of the cycle.
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};