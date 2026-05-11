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

        if (head == NULL || head->next == NULL) {
            return head;
        }

        vector<int> arr;

        ListNode* temp = head;

        // Store odd indexed nodes
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }

        if (temp != NULL) {
            arr.push_back(temp->val);
        }

        // Start from even node
        temp = head->next;

        // Store even indexed nodes
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }

        if (temp != NULL) {
            arr.push_back(temp->val);
        }

        // Put values back into linked list
        temp = head;
        int i = 0;

        while (temp != NULL) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};