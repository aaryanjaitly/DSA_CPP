#include <iostream>
using namespace std;


float Taylor_Series_of_e_using_Recursion(int x, int n){
    static float F=1,P=1;
    if(n == 0){
        return 1;
    }
    float r = Taylor_Series_of_e_using_Recursion(x,n-1);
    P = P*x;
    F = F*n;
    return(r+P/F);
}

float Taylor_Series_of_e_using_Recursion_Better(float x, float n){
    static float s = 1;

    if (n == 0)
    {
        return(s);
    }
    s = 1 + (x/n)*s;
    return(Taylor_Series_of_e_using_Recursion_Better(x,n-1));   
}

int main(){
    cout << Taylor_Series_of_e_using_Recursion(1,10) << endl;
    cout << Taylor_Series_of_e_using_Recursion_Better(1,10) << endl;
    return 0;
}