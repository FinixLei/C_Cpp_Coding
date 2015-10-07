#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
};

Node * reverse_linkedlist(Node * head) {
    if (head == NULL or head->next == NULL) {
        return head;
    }
    
    Node * t1 = head;
    Node * t2 = t1->next;
    Node * final_head = reverse_linkedlist(t2);
    t2->next = t1;
    t1->next = NULL;
    
    return final_head;
}

void print_linkedlist(Node * head) {
    while (head != NULL) {
        cout << head->data << " "; 
        head = head->next;
    }
    cout << endl;
}

int main() {
    struct Node * n1 = new Node({.data = 1, .next = NULL}); 
    struct Node * n2 = new Node({.data = 2, .next = NULL}); 
    struct Node * n3 = new Node({.data = 3, .next = NULL}); 
    
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    
    print_linkedlist(n1);
    Node * h = reverse_linkedlist(n1);
    print_linkedlist(h);
    
    return 0;
}