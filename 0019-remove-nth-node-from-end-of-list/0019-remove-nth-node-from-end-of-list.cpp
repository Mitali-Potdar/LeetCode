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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //1 pass
        ListNode* temp=new ListNode();
        temp->next = head;

        ListNode* fast = temp;
        ListNode* slow = temp;

        for(int i=1; i<=n; i++){
             fast = fast->next;
        }

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete(del);
        
        return temp->next;

        //2 pass
        // ListNode* temp = head;
        // int s = 0;
        // while(temp){
        //     s++;
        //     temp = temp->next;
        // }
        // if(s == n) {
        //     return head->next;
        // }
        // int t = s-n;
        // temp = head;
        // for(int i = 0; i < t-1; i++){
        //     temp = temp->next;
        // }
        // ListNode* del = temp->next;
        // temp -> next = temp->next->next;
        // delete(del);
        // return head;
    }
};