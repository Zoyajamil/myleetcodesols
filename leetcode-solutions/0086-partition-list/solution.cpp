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
        ListNode* slist=new ListNode(0,nullptr);
        ListNode* blist=new ListNode(0,nullptr);

        ListNode* small=slist;
        ListNode* big=blist;

        while(head!= NULL){
            if(head->val < x){
                small->next=head;
                small=small->next;
            }else{
                big->next=head;
                big=big->next;
            }
            head=head->next;
        }

        small->next=blist->next;
        big->next=nullptr;

        ListNode* result= slist->next;
        return result;
        delete slist;
        delete blist;
    }
};

//so, we divide the given list and make two new lists storing the smaller values and the higher values,
//then join the smaller list last pointer to the bigger list and return the head of the smaller list 
//also we delete the two lists we create 
