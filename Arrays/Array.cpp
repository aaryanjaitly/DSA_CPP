#include <iostream>
using namespace  std;


class Array
{
private:
    int *A;
    int size;
    int length;
public:

Array(int Size){
    this->size = Size;
    this->A = new int[this->size];
    this->length = 0;
}

void Get_size(){
    cout << this->size << endl;
}   

void Get_length(){
    cout << this->length << endl;
}

int * Get_Array(){
    return(this->A);
}

void Fill_Array(){
    for (int i = 0; i < this->size; i++)
    {
        cout << "Enter Your Element: ";
        int n;
        cin >> n;
        this->A[i] = n;
        this->length++;
    }
}

void Print_Array(){
    for (int i = 0; i < this->length; i++)
    {
        cout << this->A[i] << " ";
    } 
    cout << endl;
}

void Append(int n){
    this->A[this->length] = n;
    this->length++;
    if (this->length > size)
    {
        cout << "Out of Range" << endl;
    }
    
}

void Insert(int pos, int n){
    if(pos < this->size && this->length < size && pos >= 0){
        for(int i = this->length; i > pos; i--){
            this->A[i] =  this->A[i-1];
        }
        this->A[pos] = n;
        this->length++;
    }
    else{
        cout << "Out of Range" << endl;
    }
}

int Delete(int pos){
    int del;
    if(pos < this->size & pos >= 0 & pos < length){
        del = this->A[pos];
        for(int i = pos; i < length-1; i++){
            this->A[i] = this->A[i+1];
        }
        this->length--;
        return(del);
    }
    else{
        return -1;
    }
}

int Pop(){
    if(this->length > 0){
        this->length--;
        int pop = this->A[this->length];
        return(pop);
    }
    else{
        return -1;
    }
}

bool Is_Sorted(){
    int i = 0;
    while (i != ((this->length)-1))
    {
        if(this->A[i] > this->A[i+1]){
            return false;
        }
        i++;
    }
    return true;
}

int Linear_Search(int val){
    int i = 0;
    if(this->length == 0){
        return -1;
    }
    while(this->A[i] != val && i < this->length){
        i++;
        if (i == this->length){
            return -1;
        }
    }
        return i;
}

int Binary_Search(int val){
    int low = 0;
    int high = (this->length)-1;

    if(Is_Sorted()){
        while (low <= high)
        {   
            int mid = (low+high)/2;
            if (val == this->A[mid]){
                return mid;
            }
            else if (val < this->A[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
    }
    return -1;
}

int Get(int i){
    if (i >= this->length || i < 0){
        return -1;
    }
    return this->A[i];
}

void Set(int i, int val){
    if (i >= this->length || i < 0){
        cout << "Wrong Index" << endl;
    }
    this->A[i] = val;
}

int Max(){
    int max = this->A[0];
    for(int i = 0; i < this->length-1; i++){
        if (this->A[i+1] > max)
        {
            max = this->A[i+1];
        }
    }
    return(max);
}

int Min(){
    int min = this->A[0];
    for(int i = 0; i < this->length-1; i++){
        if (this->A[i+1] < min)
        {
            min = this->A[i];
        }
    }
    return(min);
}

int Sum(){
    int sum = 0;
    for(int i = 0; i < this->length; i++){
        sum += this->A[i];
    }
    return(sum);
}

int Avg(){
    int sum = this->Sum();
    length = (sizeof(this->A))/(sizeof(this->A[0]));
    return(sum/length);
}

void Reverse(){
    int start;
    int i;
    int j;
    for(i=0,j=(this->length)-1;i < j;i++,j--){
        start = this->A[i];
        this->A[i] = this->A[j];
        this->A[j] = start;
    }
}

void Right_Shift(){
    for(int i = this->length; i>0; i--){
        this->A[i] = this->A[i-1];
    }
    this->A[0] = 0;
}

void Left_Shift(){
    for(int i = 0; i<this->length-1; i++){
        this->A[i] = this->A[i+1];
    }
    this->A[(this->length)-1] = 0;
}

void Right_Rotate(){
    int last = this->A[(this->length)-1];
    for(int i = this->length; i>0; i--){
        this->A[i] = this->A[i-1];
    }
    this->A[0] = last;
}

void Left_Rotate(){
    int first = this->A[0];
    for(int i = 0; i<this->length-1; i++){
        this->A[i] = this->A[i+1];
    }
    this->A[(this->length)-1] = first;
}

Array *Merge(Array *B){
    Array *C = new Array((this->size) + (B->size));
    C->length = this->length + B->length;
    int i = 0;

    for (int j = 0; j < this->length; j++,i++)
    {
        C->A[j] = this->A[j];
    }
    for (int j = 0; j < B->length; j++,i++)
    {
        C->A[i] = B->A[j];
    }
    return C;
}
};

int main(){

    int n;
    cout << "Enter Size of an Aray: ";
    cin >> n;
    Array *A1 = new Array(n);   

    return 0;
}
