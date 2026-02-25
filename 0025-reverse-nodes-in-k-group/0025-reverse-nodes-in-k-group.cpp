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
    ListNode *findknode(ListNode *head,int k){
        k-=1;
        while(head!=NULL && k>0){
            k--;
            head=head->next;
        }
        return head;
    }
    ListNode *reverseList(ListNode *head) {

        ListNode *curr = head, *prev = nullptr, *next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp= head;
        ListNode*prevlast=nullptr;
        while(temp!=NULL){
            ListNode*kthnode=findknode(temp,k);
            if(kthnode==NULL){
                if(prevlast) prevlast->next=temp;
                break;
            }
            ListNode*nextnode=kthnode->next;
            kthnode->next=NULL;
            ListNode* newhead = reverseList(temp);
            if(temp==head){
                head=newhead;
            }
            else prevlast->next=newhead;
            temp->next=nextnode;
            prevlast=temp;
            temp=nextnode;
        }
        return head;
    }
};