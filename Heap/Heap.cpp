#include <iostream>
using namespace std;

void insert(int A[],int n){
    int temp,i = n;
    temp = A[n];

       while(i>1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
       }
       A[i] = temp;
}
 
void Delete(int A[], int n) {
    int i = 1, j = 2 * i;
    int x = A[1];  
    A[1] = A[n];  
    n--;  

    while (j <= n) { 
        if (j < n && A[j + 1] > A[j]) {
            j = j + 1;
        }

        if (A[i] < A[j]) {
            swap(A[i], A[j]);
            i = j;  
            j = 2 * i; 
        } else {
            break; 
        }
    }
}

 
int main(){
    int A[100] = {0,40,35,15,30,10,12,6,5,20,50,60};
    for(int i = 1; i<10; i++){
        cout << A[i] << "  ";
    }
    cout << endl;
    insert(A,10);
    insert(A,11);
    for(int i = 1; i<12; i++){
        cout << A[i] << "  ";
    }
    cout << endl;
    Delete(A,11);
    for(int i = 1; i<11; i++){
        cout << A[i] << "  ";
    }
    cout << endl;
    Delete(A,10);
    for(int i = 1; i<10; i++){
        cout << A[i] << "  ";
    }
    cout << endl;
    return 0;
}