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
    ListNode* oddEvenList(ListNode* head) {

        // Edge cases
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Initialize pointers
        ListNode* odd = head;
        ListNode* even = head->next;

        // Store starting point of even list
        ListNode* evenHead = even;

        // Rearrange links
        while (even != NULL && even->next != NULL) {

            // Connect odd nodes
            odd->next = odd->next->next;
            odd = odd->next;

            // Connect even nodes
            even->next = even->next->next;
            even = even->next;
        }

        // Attach even list after odd list
        odd->next = evenHead;

        return head;
    }
};