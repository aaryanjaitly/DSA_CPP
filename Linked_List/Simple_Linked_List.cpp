#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Simple_Linked_List
{
private:
    Node* head;
public:
    Simple_Linked_List(){
        this->head = NULL;
    }
    void Print_Linked_List(){
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void Insert_at_Beginning(int val){
        if(this->head == NULL){
            Node *new_node = new Node();
            new_node->data = val;
            new_node->next =  NULL;
            head = new_node;
        }
        else{
            Node *new_node = new Node();
            new_node->next =  this->head;
            new_node->data =  val;
            head = new_node;
        }
    } 
    void Insert_at_end(int val){
        Node *temp = this->head;
        if(temp == NULL){
            Insert_at_Beginning(val);
            return;
        }
        while (temp->next != NULL)
        {
            temp =  temp->next;
        }
        Node *new_node = new Node();
        new_node->data =  val;
        new_node->next =  NULL;
        temp->next = new_node;
    }
    void Insert_at_index(int index, int val){
        if(index == 0){
            this->Insert_at_Beginning(val);
            return;
        }
        Node *temp = this->head;
        for (int i = 0; i < index-1; i++)
        {    
            temp =  temp->next ;
        }
        Node* new_node = new Node();
        new_node->data=  val;
        new_node->next = temp->next;
        temp->next =  new_node;
    }
    int Delete_at_Beginning(){
        if(this->head == NULL){
            return -1;
        }
        int val = this->head->data;
        this->head = this->head->next;
        return(val);
    }
    int Delete_at_End(){
        Node* temp = this->head;
        while (temp->next->next !=NULL)
        {
            temp = temp->next;
        }
        int val = temp->next->data;
        temp->next = NULL;
        return(val);
    }
    int Delete_at_Index(int index){
        Node *temp = this->head;
        for (int i = 0; i < index-1; i++)
        {    
            temp =  temp->next ;
        }
        int val = temp->next->data;
        temp->next = temp->next->next;
        return(val);
    }
    int No_of_Nodes(){
        Node *temp = this->head;
        int count = 0;
        while (temp != NULL)
        {
            temp =  temp->next;
            count++;
        }
        return(count);
    }
    int Sum_of_Nodes(){
        Node *temp = this->head;
        int sum = 0;
        while (temp != NULL)
        {   
            sum += temp->data;
            temp =  temp->next;
        }
        return(sum);
    }
    int MAX(){
        Node *temp = this->head;
        int max = temp->data;
        while (temp != NULL)
        {
            if(temp->data > max){
                max = temp->data;
            }
            temp=temp->next;
        }
        return(max);
    }
    int MIN(){
        Node *temp = this->head;
        int min = temp->data;
        while (temp != NULL)
        {
            if(temp->data < min){
                min = temp->data;
            }
            temp=temp->next;
        }
        return(min);
    }
    Node* Linear_Search(int val){
        Node *temp = this->head;
        while(temp->data != val && temp != NULL)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return NULL;
        }
        else{
            return temp;
        }
    }
    void Reverse_linked_list(){
        Node* p = this->head;
        Node *q = NULL;
        Node *r = NULL;
        while (p != NULL)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        this->head = q;
    }
};

int main(){
    Simple_Linked_List* l = new Simple_Linked_List();
    l->Insert_at_Beginning(10);
    l->Insert_at_Beginning(9);
    l->Insert_at_Beginning(8);
    l->Insert_at_Beginning(7);
    l->Insert_at_Beginning(6);
    l->Insert_at_Beginning(5);
    l->Insert_at_Beginning(4);
    l->Insert_at_Beginning(3);
    l->Insert_at_Beginning(2);
    l->Insert_at_Beginning(1);
    l->Insert_at_Beginning(0);
    l->Print_Linked_List();
    l->Reverse_linked_list();
    l->Print_Linked_List();

    return 0;
}