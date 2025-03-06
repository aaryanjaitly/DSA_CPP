#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    int size;
    int f;
    int r;
    T* Q;
public:
    Queue(int size){
        this->size = size;
        this->f = -1;
        this->r = -1;
        this->Q = new T[this->size];
    }
    void Enquene(T val){
        if(r == this->size){
            cout << "Queue is Full" << endl;
        }
        this->r++;
        this->Q[r] = val;
    }
    T dequeue(){
        if(this->r == this->f){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        this->f++;
        return(this->Q[this->f]);
    }
    bool Is_Empty(){
        if(this->f ==  this->r){
            return true;
        }
        else{
            return false;
        } 
    }
    bool Is_Full(){
        if(this->r == this->size){
            return true;
        }
        else{
            return false;
        } 
    }
    T first(){
        if(this->Is_Empty() == true){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else{
            return this->Q[this->f+1];
        }
    }
    T last(){
        if(this->Is_Empty() == true){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else{
            return this->Q[this->r];
        }
    }
};

template <typename T>
class Circular_Queue{
    private:
        int size;
        int f;
        int r;
        T* Q;
    public:
    Circular_Queue(int size){
        this->size = size;
        this->f = 0;
        this->r = 0;
        this->Q = new T[this->size];
    }
    bool Circular_is_full(){
        if((this->r + 1) % this->size == this->f){
            return true;
        }
        else{
            return false;
        }
    }
    bool Circular_is_empty(){
        if(this->r == this->f){
            return true;
        }
        else{
            return false;
        }
    }
    void Circular_Enqueue(int val){
        if(this->Circular_is_full()){
            cout << "Queues is Full" << endl;
        }
        else{
            this->r = (this->r+1)%this->size ;
            this->Q[this->r] =  val;
        }
    }
    T last(){
        if(this->Circular_is_empty() == true){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else{
            return this->Q[this->r];
        }
    }
    T first(){
        if(this->Circular_is_empty() == true){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else{
            return this->Q[this->f+1];
        }
    }
    T dequeue(){
        if(this->Circular_is_empty() == true){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        this->f = (this->f+1)%this->size ;
        return(this->Q[this->f]);
    }
};

int main(){
    Queue<int> *q1 = new Queue<int>(10);
    // cout << q1->first() << endl;
    // cout << q1->Is_Empty() << endl;
    // cout << q1->Is_Full() << endl;
    // cout << q1->dequeue() << endl;
    // cout << q1->last() << endl;
    q1->Enquene(1);
    q1->Enquene(2);
    q1->Enquene(3);
    q1->Enquene(4);
    q1->Enquene(5);
    q1->Enquene(6);
    q1->Enquene(7);
    q1->Enquene(8);
    q1->Enquene(9);
    q1->Enquene(10);
    // q1->Enquene(11);
    // cout << q1->first() << endl;
    // cout << q1->Is_Empty() << endl;
    // cout << q1->Is_Full() << endl;
    // cout << q1->last() << endl;


    Circular_Queue<int> *q2 = new Circular_Queue<int>(10);
    // cout << q2->Circular_is_empty() << endl;
    q2->Circular_Enqueue(1);
    q2->Circular_Enqueue(2);
    q2->Circular_Enqueue(3);
    q2->Circular_Enqueue(4);
    q2->Circular_Enqueue(5);
    q2->Circular_Enqueue(6);
    q2->Circular_Enqueue(7);
    q2->Circular_Enqueue(8);
    q2->Circular_Enqueue(9);
    // cout << q2->last() << endl; 
    // cout << q2->first() << endl;
    // cout << q2->Circular_is_full() << endl;
    // q2->dequeue();
    // cout << q2->Circular_is_full() << endl;
    return 0;
}