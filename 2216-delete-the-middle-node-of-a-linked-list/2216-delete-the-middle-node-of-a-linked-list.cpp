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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        if(head->next->next == NULL){
            head->next = NULL;
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* del = prev->next;
        prev->next = prev->next->next;
        delete (del);
        // while(fast && fast->next && fast->next->next && fast->next->next->next){
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        // ListNode* del = slow->next;
        // slow->next = del->next;
        // delete (del);
        return head;
    }
};