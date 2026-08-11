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
    ListNode* merge(ListNode* l, ListNode* r){
        ListNode dummy(-1);
        ListNode* temp= &dummy;

        while(l && r){
            if(l->val < r->val){
                temp->next=l;
                l=l->next;
            }else{
                temp->next=r;
                r=r->next;
            }
        temp= temp->next;
        }
        temp->next= (l) ? l : r;
        return dummy.next;
    }

    ListNode* findmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* mid= findmid(head);
        ListNode* righthead= mid->next;
        mid->next=NULL;
        ListNode* lefthead= head;

        lefthead= sortList(lefthead);
        righthead=sortList(righthead);
        return merge(lefthead,righthead);
    }
};
