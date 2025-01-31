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
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (fast == NULL) {
            ListNode* newHead = slow->next;
            delete(head);
            return newHead;
        }
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* target = slow->next;
        slow->next = target->next;
        delete(target);
        return head;
    }
};