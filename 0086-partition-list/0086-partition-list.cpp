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
    ListNode* partition(ListNode* head, int x) {
         ListNode* small = new ListNode(0); // small LL
        ListNode* large = new ListNode(0); // large LL

        ListNode* smallp = small; // preserving small for future
        ListNode* largep = large; // preserving large for future

        while(head!=NULL) // building the 2 new LL
        {
            if(head->val < x) // LL having values less than x 
            {
                smallp->next = head;
                smallp = smallp->next;
            }
            else  // LL having values greater than x
            {
                largep->next = head;
                largep = largep->next;
            }
            head = head->next;
        }
        smallp->next = large->next; // both list connected
        largep->next = NULL; // at the end of large LL, Null should come
        return small->next;
    }
};