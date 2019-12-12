#include <iostream>
using namespace std;

class Node{
    public :
        int data;
        Node* next;
};

void append(Node** head_ref, int new_data){
    //Allocate new node
    Node* new_node = new Node();

    //Create another node called last to determine the last node
    //Node* last = (*head_ref);
    
    //Make new data as new_node data
    new_node->data = new_data;

    //Connect new_node head to the NULL cause it's going to be the last node
    new_node->next = NULL;

    //Check if the head is null. If the head is null, we can just make a new node as a head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
    }else{
        Node* last = (*head_ref);
        //Else if the head is not empty then we must to find the last node using an iteration untill we find the node which have Null next
        while (last->next != NULL)
        {
            last = last->next;
        }
        //Connect the last next to new node
        last->next = new_node;
    }
}

void peek(Node* n){
    if (n != NULL){
        cout << n->data << endl;
    }else{
        cout << "Empty List of Queque" << endl;
    }
}

void pop(Node** n){
    Node* temp = new Node();
    if (*n == NULL){
        cout << "Empty Queque\n";
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
        cout << "Empty List of Queue";
    }else{    
        while(n != NULL){
            cout << n->data << " ";
            n = n->next;
        }
    }
    cout << endl;
}

int main(){
    //start empty list
    Node * head = NULL;

    //start an iteration of the menu
    bool condition = true;
    while (condition)
    {
        cout << "Program tipe data stack\n";
        cout << "1. Append data \n2. Pop data \n3. Peek data \n4. Print Queque \n5. Keluar \n";
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
            append(&head, inputData);
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