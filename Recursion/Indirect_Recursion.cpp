#include <iostream>
using namespace std;


void Indirect_Recursion_B(int n);

void Indirect_Recursion_A(int n){
    if(n>0){
        cout << n << " A ";
        Indirect_Recursion_B(n-1);
    }
}

void Indirect_Recursion_B(int n){
    if(n > 1){
        cout << n << " B " ;
        Indirect_Recursion_A(n/2);
    }
}

int main(){
    Indirect_Recursion_A(20);
    cout << endl;
    return 0;
}