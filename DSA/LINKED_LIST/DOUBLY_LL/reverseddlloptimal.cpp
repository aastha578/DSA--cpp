#include <iostream>
#include <vector>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1) {
        data = data1;
        next = NULL;
        prev = NULL;
    }
};

// Convert array to DLL
Node* ConvertToDLL(vector<int> arr) {

    if(arr.size() == 0) return NULL;

    Node* head = new Node(arr[0]);

    Node* previous = head;

    for(int i = 1; i < arr.size(); i++) {

        Node* temp = new Node(arr[i], NULL, previous);

        previous->next = temp;

        previous = temp;
    }

    return head;
}

// Print DLL
void PrintDLL(Node* head) {

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Reverse DLL using pointer swapping
Node* reverseDLL(Node* head)
{
    Node* current = head;
    Node* last = NULL;

    while(current != NULL)
    {
        // Store previous pointer
        last = current->prev;

        // Swap prev and next
        current->prev = current->next;
        current->next = last;

        // Move to next node
        current = current->prev;
    }

    // Update head
    if(last != NULL){
        head = last->prev;
    }

    return head;
}

// MAIN
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    Node* head = ConvertToDLL(arr);

    cout << "Original DLL: ";
    PrintDLL(head);

    head = reverseDLL(head);

    cout << "Reversed DLL: ";
    PrintDLL(head);

    return 0;
}