#include <iostream>
using namespace std;


int Fibonacci_Series_using_Recursion(int n){
    if(n <= 1){
        return n;
    }
    return(Fibonacci_Series_using_Recursion(n-2)+Fibonacci_Series_using_Recursion(n-1));
}

int Fibonacci_Series_using_Recursion_Better(int n, int *F){
    if(n <= 1){
        F[n] = n;
        return n;
    }
    else{
        if(F[n-1] == -1){
            F[n-1] = Fibonacci_Series_using_Recursion_Better(n-1,F);
        }
        if(F[n-2] == -1){
            F[n-2] = Fibonacci_Series_using_Recursion_Better(n-2,F);
        }
        F[n] = F[n-1]+F[n-2];
        return(F[n-2]+F[n-1]);
    }
}

int main(){
    int n = 7;
    cout << Fibonacci_Series_using_Recursion(n) << endl;
    int F[n];
    for(int i = 0; i <n; i++){
        F[i] = -1;
    }
    cout << Fibonacci_Series_using_Recursion_Better(n,F) << endl;
    return 0;
}