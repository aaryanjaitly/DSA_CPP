#include <iostream>
using namespace std;


int Power_using_Recursion(int m, int n){

    if(n == 0){
        return 1;
    }
    return(Power_using_Recursion(m,n-1)*m);
    
}

int Power_using_Recursion_Better(int m, int n){
    if(n == 0){
        return 1;
    }
    if (n%2 == 0)
    {
        return(Power_using_Recursion_Better(m*m,n/2));
    }
    else{
        return(m * Power_using_Recursion_Better(m*m,(n-1)/2));
    }
    
}

int main(){
    cout << Power_using_Recursion(2,5) << endl;
    cout << Power_using_Recursion_Better(2,5) << endl;
    return 0;
}