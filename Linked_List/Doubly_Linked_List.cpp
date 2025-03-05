#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
};

class Doubly_Linked_List
{
private:
    Node *first;
public:
    Doubly_Linked_List(int val){
        this->first = new Node();
        this->first->data =  val;
        this->first->prev = NULL;
        this->first->next = NULL;
    };
    void Insert_at_beginning(int val){
        Node *new_node = new Node();
        new_node->next = this->first;
        new_node->data = val;
        this->first->prev = new_node;
        new_node->prev = NULL;
        this->first = new_node;
    }
    void Print_Doubly_Linked_List(){
        Node *temp = this->first;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void Print_Doubly_Linked_List_in_Reverse(){
        Node *temp = this->first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp != NULL)  
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    //Rest is Similar to Simple_linked_list;

};


int main(){
    Doubly_Linked_List* l = new Doubly_Linked_List(10);
    l->Insert_at_beginning(9);
    l->Insert_at_beginning(8);
    l->Insert_at_beginning(7);
    l->Insert_at_beginning(6);
    l->Insert_at_beginning(5);
    l->Insert_at_beginning(4);
    l->Insert_at_beginning(3);
    l->Insert_at_beginning(2);
    l->Insert_at_beginning(1);
    l->Insert_at_beginning(0);
    l->Print_Doubly_Linked_List();
    l->Print_Doubly_Linked_List_in_Reverse();
    return 0;
}