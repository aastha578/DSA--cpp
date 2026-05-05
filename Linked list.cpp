
/*

Node* head = new Node();
(*head).data = 10;
(*head).next = NULL;    


//code of node creation and traversal of linked list
#include <bits/stdc++.h> 
using namespace std;
struct Node
{
    int data ;
    Node* next;
};
//function to create a new node
Node* createNode(int data)
{
    Node* newNode = new Node();
    (*newNode).data = data;
    (*newNode).next = NULL;
    return newNode;
}           

//class to implement node
class Node{
    public:
    int data ;
    Node* next; 
};

*/


//convert arrat to linked list and print the linked list
#include <bits/stdc++.h>
using namespace std;

// Step 1: Define Node
struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

// Step 2: Convert Array to Linked List
Node* convertArrToLL(vector<int>& arr) {
    if(arr.size() == 0) return NULL;

    Node* head = new Node(arr[0], NULL);
    Node* temp = head;

    for(int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i], NULL);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

// Step 3: Print Linked List
void printLL(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Step 4: Length
int lengthofLL(Node* head) {
    int count = 0;
    Node* temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Step 5: Search Position
int searchPosition(Node* head, int target) {
    int pos = 1;
    Node* temp = head;

    while(temp != NULL) {
        if(temp->data == target) return pos;
        temp = temp->next;
        pos++;
    }

    return -1;
}

// Step 6: Delete Head
Node* deleteHead(Node* head) {
    if(head == NULL) return NULL;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}
//step 7: Delete Tail
Node* deleteTail(Node* head) {
    // Case 1: empty list
    if(head == NULL) return NULL;

    // Case 2: only one node
    if(head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;

    // Move to second-last node
    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    // Delete last node
    delete temp->next;
    temp->next = NULL;

    return head;
}

//delete a node at a kth position
Node* deleteAtk(Node* head, int k) {
    if(head == NULL) return NULL;

    // Case 1: delete head
    if(k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    int count = 1;

    while(temp != NULL) {
        count++;
        if(count == k) {
            prev->next = temp->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
        
    }

    return head;
}

//deletion based on value 
Node* deleteByValue(Node* head, int value) {
    if(head == NULL) return NULL;

    // Case 1: value at head
    if(head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL) {
        if(temp->data == value) {
            prev->next = temp->next;
            delete temp;
            return head;
        }

        prev = temp;
        temp = temp->next;
    }

    return head; // value not found
}


Node* insertAtHead(Node* head ,int val)
{
    Node* newNode= new Node(val, head);
    return newNode ;
}

Node* insertAtTail(Node* head, int value) {
    Node* newNode = new Node(value, NULL);

    // Case 1: empty list
    if(head == NULL) {
        return newNode;
    }

    Node* temp = head;

    // Move to last node
    while(temp->next != NULL) {
        temp = temp->next;
    }

    // Attach new node
    temp->next = newNode;

    return head;
}


Node* insertAtPosition(Node* head, int value, int k) {
    // Case 1: insert at head
    if(k == 1) {
        return new Node(value, head);
    }

    Node* temp = head;
    int count = 1;

    // Move to (k-1)th node
    while(temp != NULL && count < k-1) {
        temp = temp->next;
        count++;
    }

    // If position is invalid
    if(temp == NULL) return head;

    // Create new node
    Node* newNode = new Node(value, temp->next);

    // Link it
    temp->next = newNode;

    return head;
}

Node* insertBeforeValue(Node* head, int target, int value) {
    if(head == NULL) return NULL;

    // Case: insert before head
    if(head->data == target) {
        return new Node(value, head);
    }

    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL) {
        if(temp->data == target) {
            Node* newNode = new Node(value, temp);
            prev->next = newNode;
            return head;
        }

        prev = temp;
        temp = temp->next;
    }

    return head; // value not found
}

Node* insertAfterValue(Node* head, int target, int value) {
    Node* temp = head;

    while(temp != NULL) {
        if(temp->data == target) {
            Node* newNode = new Node(value, temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }

    return head; // value not found
}

int main() {
    vector<int> arr = {1,2,3,4,5};

    Node* head = convertArrToLL(arr);

    printLL(head);

    cout << "Length: " << lengthofLL(head) << endl;

    int target = 3;
    int pos = searchPosition(head, target);

    if(pos != -1) {
        cout << "Found at position: " << pos << endl;
    } else {
        cout << "Not Found" << endl;
    }

    // Delete head
    head = deleteHead(head);

    cout << "After deleting head:" << endl;
    printLL(head);

    head = deleteTail(head);
    cout<< "After deleting tail:" << endl;
    printLL(head);

    int k = 3;

    head = deleteAtk(head, k);

    cout << "After deleting " << k << "th node:" << endl;
    printLL(head);

    head = deleteByValue(head, 3);
    printLL(head);

    head = insertAtHead(head, 100);
    printLL(head);

    head = insertAtTail(head, 5);
    printLL(head);

    head = insertAtPosition(head, 3, 3);
    printLL(head);

    head = insertAfterValue(head, 2, 99);
    cout << "After inserting 99 after 2:" << endl;
    printLL(head);

    // Insert BEFORE value
    head = insertBeforeValue(head, 3, 77);
    cout << "After inserting 77 before 3:" << endl;
    printLL(head);


    return 0;
}




//struct in node
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data ;
    Node* next;

};

//creating three nodes and link them together

int main(){

    Node* head = new Node();  // head node
    head->data = 10;
    head->next = second;

    Node* second = new Node();  // second node
    second->data = 20;
    second->next = third;

    Node* third = new Node();  // third node
    third->data = 30;
    third->next = nullptr;
}


#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data ;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr; // why used this here because when we create a new node we want to initialize the next pointer to null so that it doesn't point to any garbage value and we can easily check if the next pointer is null or not while traversing the linked list
    }
};

//creating three nodes and link them together

int main(){

    Node* head = new Node(10);  // head node
    Node* second = new Node(20);  // second node
    Node* third = new Node(30);  // third node
    
}


/*traversal of linked list*/
#include <bits/stdc++.h>
using namespace std;    
struct Node
{
    int data ;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};  

int main(){

    Node* head = new Node(10);  // head node
    Node* second = new Node(20);  // second node
    Node* third = new Node(30);  // third node
    while(temp != nullptr){
        cout << temp->data << " ";
        head = head->next;
    }
    return 0;
}   


#include <bits/stdc++.h>
using namespace std;    
struct Node
{
    int data ;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};  

int main(){

    Node* head = new Node(10);  // head node
    Node* second = new Node(20);  // second node
    Node* third = new Node(30);  // third node

    Node* temp = head;  // temporary pointer to traverse the linked list
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}   

// create 5 nodes and link them and traverse through eavch node  and print the data of each node 
#include <bits/stdc++.h>
using namespace std;    

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};  

int main() {

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    Node* temp = head; 
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}


//insertion of new node at the start of the linked list
#include <bits/stdc++.h>
using namespace std;    
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;

        next = nullptr;
    }
};

int main() {

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    //insertion of new node at the start of the linked list
    Node* newNode = new Node(5);
    newNode->next = head;
    head = newNode;

    Node* temp = head; 
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}


//insertion of new node at the end of the linked list
#include <bits/stdc++.h>


Node *InsertAtTail( Node *head , int val)
{
    Node *newNode = new Node(val);
    if(head==nullptr)
       return newNode;

    Node *temp = head ;
    while (temp ->next !=nullptr) {
        
        temp = temp->next;
    }

    temp->next = newNode;
    return head;

}



//deletion of the node fromt he start 

Node* deleteAtHead(Node* head) {
    if (head == nullptr) {
        return nullptr; // If the list is empty, return nullptr
    }
    Node* temp = head; // Store the current head node in a temporary variable
    head = head->next; // Move the head pointer to the next node
    delete temp; // Delete the old head node to free memory

    return head; // Return the new head of the list
}   


//DELETION OF THE NODE FROM THE END OF THE LINKED LIST
Node* deleteAtTail(Node* head) {
    if (head == nullptr) {
        return nullptr; // If the list is empty, return nullptr
    }
    if (head->next == nullptr) {
        delete head; // If there is only one node, delete it and return nullptr
        return nullptr;
    }

    Node* temp = head; // Start from the head of the list
    while (temp->next->next != nullptr) { // Traverse until the second last node
        temp = temp->next;
    }
    Node *toDelete = temp->next; // Store the last node to be deleted
    temp->next = nullptr; // Set the next pointer of the second last node to nullptr    
    delete toDelete;
    return head;

}

//reverse an linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr; // Initialize previous pointer to nullptr
    Node* current = head; // Start with the head of the list
    Node* next = nullptr; // Initialize next pointer

    while (current != nullptr) { // Traverse the list until the end
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current; // Move the previous pointer to the current node
        current = next; // Move to the next node in the original list
    }

    return prev; // At the end, prev will be the new head of the reversed list
}   


//midddle of the linked list
Node* findMiddle(Node* head) {
    if (head == nullptr) {
        return nullptr; // If the list is empty, return nullptr
    }

    Node* slow = head; // Initialize slow pointer to the head
    Node* fast = head; // Initialize fast pointer to the head

    while (fast != nullptr && fast->next != nullptr) { // Traverse the list
        slow = slow->next; // Move slow pointer by one node
        fast = fast->next->next; // Move fast pointer by two nodes
    }

    return slow; // When fast pointer reaches the end, slow pointer will be at the middle
}

//middle of the linked list using brute force approach
Node* findMiddle(Node* head) {          
    if (head == nullptr) {
        return nullptr; // If the list is empty, return nullptr
    }

    int count = 0; // Initialize count to keep track of the number of nodes
    Node* temp = head; // Start from the head of the list

    while (temp != nullptr) { // Traverse the list to count the nodes
        count++;
        temp = temp->next;
    }

    int middleIndex = count / 2; // Calculate the index of the middle node
    temp = head; // Reset temp to the head of the list

    for (int i = 0; i < middleIndex; i++) { // Traverse to the middle node
        temp = temp->next;
    }

    return temp; // Return the middle node
}

class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if (head == nullptr) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // 1 step
            fast = fast->next->next;     // 2 steps

            if (slow == fast) {
                return true;             // cycle detected
            }
        }

        return false; // no cycle
    }
};


//21. 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        // Dummy node to simplify logic
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy->next;
    }
};

//Leetcode : Delete the nth node from the end of the linked list

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;

        // calculate the length of the linked list
        int length =0;
        ListNode* temp = head;

        while(temp!=NULL)
        {
            temp=temp->next;
            length++;
        }

        int pos=length-n+1;
        if(pos==1)
        {
            ListNode* temp =head;
            head=head->next;
            delete temp;
            return head;
        }

        ListNode* temp= head;
        ListNode* prev= null;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            if(count=pos)
            {
                prev->next=temp->next;
                delete temp;
                break;  
            }
            prev = temp;
            temp=temp->next;

     }
     return head;
    }
}; 
        
