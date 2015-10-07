#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
};

Node * reverse_linkedlist_recursively(Node * head) {
    if (head == NULL or head->next == NULL) {
        return head;
    }
    
    Node * t1 = head;
    Node * t2 = t1->next;
    Node * final_head = reverse_linkedlist_recursively(t2);
    t2->next = t1;
    t1->next = NULL;
    
    return final_head;
}

Node * reverse_linkedlist(Node * head) {
    if (head == NULL or head->next == NULL) {
        return head;
    }
    
    Node *p1 = head; 
    Node *p2 = head->next;
    Node *p3 = p2->next;
    
    head->next = NULL; 
    
    if (p3 == NULL) {
        p2->next = p1;
        return p2;
    }
    
    while (p3->next != NULL) {
        p2->next = p1; // 一个循环体里面只做一次反转
        p1 = p2; p2 = p3; p3 = p3->next; 
    }
    
    p2->next = p1;
    p3->next = p2;
    return p3;
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
    
    print_linkedlist(n1);  // 1 2 3
    Node * h = reverse_linkedlist_recursively(n1);
    print_linkedlist(h);  // 3 2 1
    
    h = reverse_linkedlist(h); 
    print_linkedlist(h);  // 1 2 3
    
    struct Node * n4 = new Node({.data = 4, .next = NULL}); 
    n3->next = n4;
    h = reverse_linkedlist(h); 
    print_linkedlist(h);  // 4 3 2 1
    
    return 0;
}
