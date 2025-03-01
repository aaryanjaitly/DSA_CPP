#include <iostream>
using namespace std;


void Tower_of_Hanoi(int n, char A, char B, char C){
    if(n >0){
        Tower_of_Hanoi(n-1,A,C,B);
        cout << A << " to " << C << endl;
        Tower_of_Hanoi(n-1,B,A,C);
    }

}

int main(){
    Tower_of_Hanoi(3,'A','B','C');
    return 0;
}