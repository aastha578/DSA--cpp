#include <iostream>
#include <vector>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    Node* back;

    // Constructor with all parameters
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = NULL;
        back = NULL;
    }
};

// Convert array to DLL
Node* ConvertToDLL(vector<int> arr) {

    if(arr.size() == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < arr.size(); i++) {

        Node* temp = new Node(arr[i], NULL, prev);

        prev->next = temp;
        prev = temp;
    }

    return head;
}

// Print DLL
void PrintDLL(Node* head) {

    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

// Delete at head
Node* deleteAtHead(Node* head) {

    if(head == NULL) return NULL;

    Node* temp = head;

    head = head->next;

    if(head != NULL) {
        head->back = NULL;
    }

    delete temp;

    return head;
}

// Delete at tail
Node* deleteAtTail(Node* head) {

    if(head == NULL) return NULL;

    // Only one node
    if(head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->back->next = NULL;

    delete temp;

    return head;
}

// Delete at kth position
Node* deleteAtkPos(Node* head, int k) {

    if(head == NULL) return NULL;

    Node* temp = head;

    int count = 1;

    // Reach kth node
    while(temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    // Invalid position
    if(temp == NULL) return head;

    // Deleting head
    if(temp->back == NULL) {

        head = temp->next;

        if(head != NULL) {
            head->back = NULL;
        }

        delete temp;

        return head;
    }

    // Normal deletion
    Node* prev = temp->back;
    Node* next = temp->next;

    prev->next = next;

    if(next != NULL) {
        next->back = prev;
    }

    delete temp;

    return head;
}

// Delete by value
Node* deleteByValue(Node* head, int x) {

    if(head == NULL) return NULL;

    Node* temp = head;

    // Find node
    while(temp != NULL && temp->data != x) {
        temp = temp->next;
    }

    // Value not found
    if(temp == NULL) return head;

    // Deleting head
    if(temp->back == NULL) {

        head = temp->next;

        if(head != NULL) {
            head->back = NULL;
        }

        delete temp;

        return head;
    }

    // Normal deletion
    Node* prev = temp->back;
    Node* next = temp->next;

    prev->next = next;

    if(next != NULL) {
        next->back = prev;
    }

    delete temp;

    return head;
}

// Insert at head
Node* InsertAtHead(Node* head, int value) {

    Node* newNode = new Node(value, head, NULL);

    if(head != NULL) {
        head->back = newNode;
    }

    return head = newNode;
}

Node* InsertAtTail(Node* head, int value){

    //creating new node
    Node* newNode = new Node(value);
    // Empty list
    if(head == NULL){
        return newNode;
    }

    Node* temp = head;

    // Move to last node
    while(temp->next != NULL){
        temp = temp->next;
    }
   
    // Connect nodes
    temp->next = newNode;
    newNode->back = temp;

    return head;
}

Node* InsertAtK(Node* head, int value, int k)
{
    // Insert at head
    if(k == 1){
        return InsertAtHead(head, value);
    }

    Node* temp = head;
    int count = 1;

    // Reach (k-1)th node
    while(temp != NULL && count < k-1){
        temp = temp->next;
        count++;
    }

    // Invalid position
    if(temp == NULL){
        return head;
    }

    Node* front = temp->next;

    // Insert at tail
    if(front == NULL){
        return InsertAtTail(head, value);
    }

    // Insert in middle
    Node* newNode = new Node(value, front, temp);

    temp->next = newNode;
    front->back = newNode;

    return head;
}

Node* InsertAfterValue(Node* head, int x, int value){

    Node* temp = head;

    // Find node with value x
    while(temp != NULL && temp->data != x){
        temp = temp->next;
    }

    // Value not found
    if(temp == NULL){
        return head;
    }

    Node* front = temp->next;

    // Insert at tail
    if(front == NULL){

        Node* newNode = new Node(value, NULL, temp);

        temp->next = newNode;

        return head;
    }

    // Insert in middle
    Node* newNode = new Node(value, front, temp);

    temp->next = newNode;
    front->back = newNode;

    return head;
}
// MAIN
int main() {

    vector<int> arr = {1, 2, 3, 4};

    Node* head = ConvertToDLL(arr);

    cout << "Original DLL: ";
    PrintDLL(head);

    head = deleteAtHead(head);
    cout << "After deleting head: ";
    PrintDLL(head);

    head = deleteAtTail(head);
    cout << "After deleting tail: ";
    PrintDLL(head);

    head = deleteByValue(head, 3);
    cout << "After deleting by value: ";
    PrintDLL(head);

    head = deleteAtkPos(head, 1);
    cout << "After deleting at position 1: ";
    PrintDLL(head);

    head = InsertAtHead(head, 10);
    cout << "After inserting at head: ";
    PrintDLL(head);

    head = InsertAtTail(head, 20);
    cout << "After inserting at tail: ";
    PrintDLL(head);

    head= InsertAtK(head, 15, 3);
    cout<< "After inserting 15 at position 3: ";
    PrintDLL(head);

    head = InsertAtK(head, 99, 3);
    cout << "After inserting 99 at position 3: ";
    PrintDLL(head);

    // Insert after value
    head = InsertAfterValue(head, 2, 50);
    cout << "After inserting 50 after value 2: ";
    PrintDLL(head);

    return 0;
}