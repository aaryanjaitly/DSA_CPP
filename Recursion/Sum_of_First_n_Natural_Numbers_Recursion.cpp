#include <iostream>
using namespace std;

int Sum_of_First_n_Natural_Numbers_Recursion(int n){
    if (n > 0)
    {
        return(Sum_of_First_n_Natural_Numbers_Recursion(n-1)+n);
    }
    return 0;
}

int main(){
    cout << Sum_of_First_n_Natural_Numbers_Recursion(10) << endl;
    return 0;
}
/* Better to Use n(n+1)/2 -> O(1)*/