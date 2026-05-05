#include <iostream>
#include <vector>
using namespace std;


//Creation of node of doubly linked list
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



//Conversion of array to doubly linked list

Node* ConvertToDLL(vector<int>arr)
{
    if(arr.size() == 0) return NULL;
    
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);

        prev->next = temp;
        prev = temp;
    }
    return head;
    
}

void PrintDLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;

}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    Node* head = ConvertToDLL(arr);
    PrintDLL(head);
    return 0;
}