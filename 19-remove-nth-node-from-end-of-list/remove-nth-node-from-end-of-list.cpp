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
        ListNode* temp = head;
        int length = 0;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        if (n == length) {
            ListNode* newHead = head->next;
            delete(head);
            return newHead;
        }
        temp = head;
        for (int i = 1; i < length - n; i++) {
            temp = temp->next;
        }
        ListNode* target = temp->next;
        temp->next = target->next;
        delete(target);
        return head;
    }
};