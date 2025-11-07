// LeetCode: Intersection of Two Linked Lists

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        
        ListNode* a = headA;
        ListNode* b = headB;

        // When one pointer hits NULL, move it to the other list's head
        while (a != b) {
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a; // can be NULL or the intersection node
    }
};

