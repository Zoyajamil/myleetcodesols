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

    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode dummy(-1);
        ListNode* temp=&dummy;

        while(l1 && l2){
            if(l1->val<=l2->val){
                temp->next=l1;
                l1=l1->next;
            }else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        temp->next=(l1) ? l1 : l2;
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
        if(!head || !head->next) return head; //if only one element 

        //split list

        ListNode* mid=findmid(head);
        ListNode* righthead=mid->next;
        mid->next=NULL;
        ListNode* lefthead=head;
         
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        return merge(lefthead,righthead);
    }
};
