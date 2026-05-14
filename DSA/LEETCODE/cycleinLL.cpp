//using two pinter approach 

class Solution {
public:

    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;

            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};


//using hashing 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:

    bool hasCycle(ListNode *head) {

        map<ListNode*, bool> visited;

        ListNode* temp = head;

        while (temp != NULL) {

            // Node already visited
            if (visited[temp] == true) {
                return true;
            }

            // Mark visited
            visited[temp] = true;

            temp = temp->next;
        }

        return false;
    }
};

//Find the node where the cycle begins

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        
        map<ListNode*, bool> visited;

        ListNode* temp = head;

        while (temp != NULL) {

            if (visited[temp] == true) {
                return temp;
            }

            visited[temp] = true;

            temp = temp->next;
        }

        return NULL;
    }
};


//OPTIMAL APPROACH
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:

    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {

                ListNode* entry = head;

                while (entry != slow) {

                    entry = entry->next;
                    slow = slow->next;
                }

                return entry;
            }
        }

        return NULL;
    }
};