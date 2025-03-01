#include <iostream>
using namespace std;


int Nested_Recursion(int n){
    if (n > 100)
    {
        cout << n-10 << " ";
        return (n-10);
    }
    else{
        return(Nested_Recursion(Nested_Recursion(n+11)));
    }
}

int main(){
    Nested_Recursion(90);
    cout << endl;
    return 0;
}