#include <iostream>
using namespace std;


int x = 0; /* Global Variable */
int Static_Recursion(int n){
    if(n > 0){
        x++;
        return(Static_Recursion(n-1)+x);
    }
    return 0;
}

int main(){
    cout << Static_Recursion(10) << endl;
    return 0;
}