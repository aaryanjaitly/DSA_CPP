#include <iostream>
using namespace std;


void Tail_Recursion(int i){

    if(i > 0){
        Tail_Recursion(i-1);
        cout << i-1 << endl;
    }
}

int main(){
    Tail_Recursion(10);
    return 0;
}