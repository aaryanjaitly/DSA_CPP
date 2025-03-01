#include <iostream>
using namespace std;


int Factorial_using_Recrsion(int n){
    if (n == 0){
        return 1;
    }
    return(Factorial_using_Recrsion(n-1)*n);
}

int main(){
    cout << Factorial_using_Recrsion(5) << endl;
    return 0;
}