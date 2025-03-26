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
/*Quick Sort*/
int Partition(int A[],int l, int h){
    int pivot = A[l];
    int i = l; 
    int j = h;
    do
    {
        do(i++);while(A[i] <= pivot);
        do(j--);while(A[j] > pivot);

        if(i < j){
            swap(A[i],A[j]);
        }

    } while (i<j);
    swap(A[l],A[j]);
    return j;
}
void quick_sort(int A[], int l, int h){
    int j;
    if(l<h){
        j=Partition(A,l,h);
        quick_sort(A,l,j);
        quick_sort(A,j+1,h);
    }
}
/*Merge Sort*/
void merge(int A[], int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = 0;
    int B[100];

    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    for (; i <= mid; i++) {
        B[k++] = A[i];
    }

    for (; j <= h; j++) {
        B[k++] = A[j];
    }

    for (i = l; i <= h; i++) {
        A[i] = B[i - l];
    }
}

void merge_sort(int A[], int l, int h){
    
    if(l<h){
        int mid = (l+h)/2;
        merge_sort(A,l,mid);
        merge_sort(A,mid+1,h);
        merge(A,l,mid,h);  
    }
}
/*Count Sort*/
int findmax(int A[], int len){
    int max = INT32_MIN;
    for(int i = 0; i < len;i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}
void count_sort(int A[], int len){
    int max;
    int *c;
    max = findmax(A,len);
    c = new int[max+1];
    for(int i = 0; i < len; i++){
        c[A[i]]++;
    }
    int i = 0;
    int j = 0;
    while (i<max+1)
    {
        if(c[i] > 0){
            A[j++] = i;
            c[i]--;
        }
        else{
            i++;
        }
    }
}


int main(){
    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int length =  sizeof(A)/sizeof(A[0]);
    
    cout << "Unsorted: ";
    print_array(A,length);
    cout << endl;

    // bubble_sort(A,10);
    // insertion_sort(A,length);
    // selection_sort(A,length);
    // quick_sort(A,0,length);
    // merge_sort(A,0,length);
    count_sort(A,length);

    cout << "Sorted: ";
    print_array(A,length);
    cout << endl;

    return 0;
}