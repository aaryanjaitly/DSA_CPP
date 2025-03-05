#include <iostream>
using namespace std;

template <typename T>
class Stack
{
public:
    int top;
    int size;
    T *A;
public:
    Stack(int size){
        this->size = size;
        this->A = new T[this->size = size];
        this->top = -1;
    }
    int Is_Empty(){
        if (this->top == -1)
        {   
            return 1;
        }
        else{
            return 0;
        }
    }
    int Is_Full(){
        if(this->top == (this->size-1)){
            return 1;
        }
        else{
            return 0;
        }
    }
    void Push(int val){
        if(this->Is_Full()){
            cout << "Over Flow" << endl;
        }
        else{
            this->top++;
            this->A[this->top] = val;
        }
    }
    int Pop(){
        if(this->Is_Empty()){
            cout << "Under Flow" << endl;
            return(-1);
        }
        else{
            int val = this->A[this->top];
            this->top--;
            return val;
        }
    }
    int Peak(int pos){
        if(Is_Empty()){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        if(pos <= this->size){
            int index = (this->top)-pos+1;
            return(this->A[index]);
        }
        else{
            cout << "Over Flow" << endl;
            return -1;
        }
    }
    int Stacktop(){
        if(Is_Empty()){
            cout << "Empty Stack" << endl;
            return -1;
        }
        else{
            return(this->A[this->top]);
        }
    }
};

struct  Node
{
    int data;
    Node *next;
};

class Stack_using_Linked_list
{
private:
    Node* top;
public:
    Stack_using_Linked_list(){
        this->top = NULL;
    }
    void Push_stack_linked_List(int val){
        if(this->top == NULL){
            Node *new_node = new Node();
            new_node->data = val;
            new_node->next = NULL;
            this->top = new_node;
        }
        else{
            Node *new_node = new Node();
            new_node->data = val;
            new_node->next = this->top;
            this->top = new_node;
        }
    }
    int Is_Empty_linked_list(){
        if(this->top == NULL){
            return 1;
        }
        else{
            return 0;
        }
    }
    int Pop_linked_list(){
        if(Is_Empty_linked_list()){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        else{
            int val = this->top->data;
            this->top =  this->top->next;
            return(val);
        }
    }
    int Peak_linked_list(int pos){
        Node *temp =  this->top;
        if(pos == 1){
            return temp->data;
        }
        for(int i = 1;i < pos && temp != NULL;i++){
            temp = temp->next;
        }
        if(temp == NULL){
            cout << "Under Flow" << endl;
            return -1;
        }
        return temp->data;
    }
    int Stacktop_linked_list(){
        if(Is_Empty_linked_list()){
            cout << "Empty Stack" << endl;
            return -1;
        }
        else{
            return(this->top->data);
        }
    }
};


bool is_balance(string expression){
    Stack<char> *s3 = new Stack<char>(expression.length());
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
            s3->Push(expression[i]);
        }
        else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if(s3->Is_Empty() == false && ((s3->Stacktop() == '(' && expression[i] == ')') ||
            (s3->Stacktop() == '{' && expression[i] == '}') ||
            (s3->Stacktop() == '[' && expression[i] == ']'))){
                s3->Pop();
            }
            else{
                return false;
            }
        }
    }
    if(s3->Is_Empty() == true){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Stack<int> *s = new Stack<int>(10);
    s->Push(1);
    s->Push(2);
    s->Push(3);
    s->Push(4);
    s->Push(5);
    s->Push(6);
    s->Push(7);
    s->Push(8);
    s->Push(9);
    s->Push(10);
    Stack_using_Linked_list *s2 = new Stack_using_Linked_list();
    s2->Push_stack_linked_List(1);
    s2->Push_stack_linked_List(2);
    s2->Push_stack_linked_List(3);
    s2->Push_stack_linked_List(4);
    s2->Push_stack_linked_List(5);
    s2->Push_stack_linked_List(6);
    s2->Push_stack_linked_List(7);
    s2->Push_stack_linked_List(8);
    s2->Push_stack_linked_List(9);
    s2->Push_stack_linked_List(10);

    string expression;
    cout << "Please Enter Your expression: ";
    cin >> (expression);
    cout << is_balance(expression) << endl; 
    return 0;
}