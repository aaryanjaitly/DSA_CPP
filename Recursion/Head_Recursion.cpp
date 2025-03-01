#include <iostream>
using namespace std;


void Head_Recursion(int i){

    if(i > 0){
        cout << i-1 << endl;
        Head_Recursion(i-1);
    }
}

int main(){
    Head_Recursion(10);
    return 0;
}