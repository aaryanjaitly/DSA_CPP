#include <iostream>
using namespace std;


void Tree_Recursion(int n){
    if (n > 0){
        cout << n;
        Tree_Recursion(n-1);
        Tree_Recursion(n-1);
    }
}

int main(){
    Tree_Recursion(3);
    cout << endl;
    return 0;
}