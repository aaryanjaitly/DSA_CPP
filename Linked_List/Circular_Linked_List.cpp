#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Circular_Linked_List
{
private:
    Node *head;
public:
    Circular_Linked_List(){
        this->head = NULL;
    };
    void Print_Circular_Linked_List(){
        Node* temp = this->head;
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != this->head);
        cout << endl;
    }
    void Insert_at_beginning(int val){
        if(this->head ==  NULL){
            Node* new_node = new Node();
            new_node->data =  val;
            new_node->next = new_node;
            head = new_node;
        }
        else{
            Node* temp = this->head;
            Node* new_node = new Node();
            new_node->data = val;
            new_node->next = this->head;
            while (temp->next != this->head)
            {
                temp = temp->next;
            }
            temp->next =  new_node;
            this->head = new_node;
        }
    }
    void Insert_at_end(int val){
        if(this->head ==  NULL){
            this->Insert_at_beginning(val);
        }
        Node* temp = this->head;
        Node* new_node = new Node();
        new_node->data = val;
        while (temp->next != this->head)
        {
            temp = temp->next;
        }
        new_node->next = temp->next; //HEAD NODE
        temp->next = new_node;
    }
    // Insert_at_index same as simple_linked_list;
    int Delete_at_Beginning(){
        if(this->head == NULL){
            return -1;
        };
        if(this->head->next == this->head){
            int val = this->head->data;
            this->head = NULL;
            return val;
        }
        Node* temp = this->head;
        while (temp->next != this->head)
        {
            temp = temp->next;
        }
        int val = temp->next->data;
        temp->next =  this->head->next;
        head = head->next;
        return val;
    }
    int Delete_at_End(){
        Node* temp = this->head;
        if(this->head == NULL || this->head->next == this->head){
            Delete_at_Beginning();
        };

        while (temp->next->next !=this->head)
        {
            temp = temp->next;
        }
        int val = temp->next->data;
        temp->next = temp->next->next;
        return(val);
    }
    // Delet_at_Index Similar as simple_linked_list;
};


int main(){
    Circular_Linked_List *l = new Circular_Linked_List();
    l->Insert_at_beginning(10);
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
    l->Insert_at_end(12);
    l->Insert_at_end(13);
    l->Print_Circular_Linked_List();
    l->Delete_at_Beginning();
    l->Print_Circular_Linked_List();
    l->Delete_at_End();
    l->Print_Circular_Linked_List();
    return 0;
}