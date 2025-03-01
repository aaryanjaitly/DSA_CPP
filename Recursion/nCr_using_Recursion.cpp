#include <iostream>
using namespace std;

/*
Pascal's Triangle!
                                    1
                                1       1
                            1       2       1
                        1       3       3       1
                    1       4       6       4       1
                1       5       10      10      5       1       
*/


int nCr_using_Recursion(int n, int r){
    if(n == r || r == 0){
        return 1;
    }
    return(nCr_using_Recursion(n-1,r-1) + nCr_using_Recursion(n-1,r));
}

int main(){
    cout << nCr_using_Recursion(4,2) << endl;
    return 0;
}