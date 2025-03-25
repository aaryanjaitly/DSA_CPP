#include <iostream>
using namespace std;

void print_array(int A[],int length){
    for(int i = 0; i <length;i++){
        cout << " " << A[i] << " ";
    }
}
/*Bubble Sort*/
void bubble_sort(int A[],int len){
    int flag = 0;
    for (int i = 0; i < len-1; i++)
    {
        flag = 0;
        for (int j = 0; j < len-1-i; j++)
        {
            if(A[j] > A[j+1]){
                swap(A[j],A[j+1]);
                flag = 1;
            }
        }
        if (flag == 0)
            {   
                break;
            }   
    }
}
/*Insertion Sort*/
void insertion_sort(int A[], int len){
    for(int i = 1; i < len;i++){
        int val =  A[i];
        int j = i-1;
        while (j >=0 && A[j] > val)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = val;
    }
}
/*Selection Sort*/
void selection_sort(int A[],int len){
    int i,j,k;
    for (i = 0; i < len-1; i++)
    {
        for(j=k=i; j<len; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        swap(A[i],A[k]);
    }
}


int main(){
    int A[] = {10,9,8,7,6,5,4,3,2,1};
    int length =  sizeof(A)/sizeof(A[0]);
    // bubble_sort(A,10);
    // insertion_sort(A,length);
    selection_sort(A,length);
    print_array(A,10);
    cout << endl;
    return 0;
}