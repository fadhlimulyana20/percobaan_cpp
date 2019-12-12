#include <iostream>
using namespace std;

class Node{
    public :
        int data;
        Node* next;
};

void push(Node** head_ref, int new_data){
    //Allocate new node
    Node* new_node = new Node();
    
    //Make new data as new_node data
    new_node->data = new_data;

    //Connect new_node head to the head ref
    new_node->next = (*head_ref);

    //Make new data as head ref
    (*head_ref) = new_node;
}

void peek(Node* n){
    if (n != NULL){
        cout << n->data << endl;
    }else{
        cout << "Empty List of stack" << endl;
    }
}

void pop(Node** n){
    Node* temp = new Node();
    if (*n == NULL){
        cout << "Stack Underflow\n";
    }else{
        //assign temp as node head
        temp = *n;

        //assign seccond node as head node
        *n = temp->next;

        //destroy connection between head node to child node
        temp->next = NULL;

        //print out popped data
        cout << temp->data << " has been popped" << endl;

        //destroy memory of head node
        free(temp);
    }
}

void printList(Node* n){
    if (n == NULL)
    {
        cout << "Empty Stack";
    }else{    
        while(n != NULL){
            cout << n->data << " ";
            n = n->next;
        }
    }
    cout << endl;
}

int main(){
    //start empy list
    Node * head = NULL;

    //start an iteration of the menu
    bool condition = true;
    while (condition)
    {
        cout << "Program tipe data stack\n";
        cout << "1. Push data \n2. Pop data \n3. Peek data \n4. Print stack \n5. Keluar \n";
        cout << "Ketik nomor untuk melanjutkan : ";
        int choice;
        cin >> choice;
        cout << endl;

        //Create a branching for given condition above
        if(choice == 5){
            condition = false;
        }else if (choice == 1)
        {
            cout << "Masukkan data : ";
            int inputData;
            cin >> inputData;
            push(&head, inputData);
        }else if (choice == 2)
        {
            pop(&head);
        }else if (choice == 3)
        {
            peek(head);
        }else if (choice == 4)
        {
            printList(head);
        }

        //print new line for the next iteration
        cout << endl;   
    }
}