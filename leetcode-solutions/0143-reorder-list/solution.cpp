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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }


        ListNode* first=head;
        ListNode* second=slow->next;
        slow->next=NULL;

        //Resverse from second till NULL

        ListNode* prev= nullptr;
        ListNode* next= nullptr;

        while(second != nullptr){
            next=second->next;
            second->next=prev;
            prev=second;
            second=next;
        }
        second=prev;

        //merge

        while(second != nullptr){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;

            first->next=second;
            second->next=temp1;

            first=temp1;
            second=temp2;
        }

    }
};
