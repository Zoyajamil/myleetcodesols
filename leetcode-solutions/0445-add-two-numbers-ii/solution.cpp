class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;

        while (temp1 || temp2 || carry) {

            int sum = carry;

            if (temp1) {
                sum += temp1->val;
                temp1 = temp1->next;
            }

            if (temp2) {
                sum += temp2->val;
                temp2 = temp2->next;
            }

            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return reverse(dummy->next);
    }
};
