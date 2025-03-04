#include <iostream>
using namespace std;


class Matrix
{
private:
    int *matrix;
    int rows;
    int cols;
public:
    Matrix(int r, int c){
        if(r > 0 && c > 0){
            this->rows = r;
            this->cols = c;
        }
    }
    void Diagonal_Matrix(){
        if(this->rows > this->cols){
            this->matrix = new int[this->rows];
        }
        else{
            this->matrix = new int[this->cols];
        }
    }
    void Set_Diagonal_Matrix_Value(int i, int j, int val){
        if(i == j && (i <= this->rows || j <= this->cols)){
            this->matrix[i-1] = val;
        }
        else{
            cout << "Wrong Index" << endl;
        }
    }
    int Get_Diagonal_Matrix_Value(int i, int j){
        if(i == j && (i <= this->rows || j <= this->cols)){
            return(this->matrix[i-1]);
        }
        else{
        return(0);
        }
    }
    void Print_Diagonal_Matrix(){
        for(int i = 0; i < this->rows; i++){
            for (int  j = 0; j < this->cols; j++)
            {
                if (i == j)
                {
                    cout << this->matrix[i] << " ";
                }
                else{
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
    void Lower_Triangualr_Matrix(){
        this->matrix = new int[(this->rows*(this->rows+1))/2];
    }
    void Set_Lower_Triangualr_Matrix_Value(int i, int j, int val){
        if(i >= j){
        this->matrix[((i*(i-1))/2)+(j-1)] = val;
        }
        else{
            cout << "Wrong Index" << endl;
        }
    }
    int Get_Lower_Triangualr_Matrix_Value(int i, int j){
        if(i >= j){
        return(this->matrix[((i*(i-1))/2)+(j-1)]);
        }
        else{
            return(0);
        }
    }
    void Print_Lower_Triangualr_Matrix(){
        for(int i = 1; i < this->rows+1; i++){
            for (int  j = 1; j < this->cols+1; j++)
            {
                if (i >= j)
                {
                    cout << this->matrix[((i*(i-1))/2)+(j-1)] << " ";
                }
                else{
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
    void Upper_Triangualr_Matrix(){
        this->matrix = new int[(this->cols*(this->cols+1))/2];
    }
    void Set_Upper_Triangualr_Matrix_Value(int i, int j, int val){
        if(i <= j){
        this->matrix[((j*(j-1))/2)+(i-1)] = val;
        }
        else{
            cout << "Wrong Index" << endl;
        }
    }
    int Get_Upper_Triangualr_Matrix_Value(int i, int j){
        if(i <= j){
        return(this->matrix[((j*(j-1))/2)+(i-1)]);
        }
        else{
            return(0);
        }
    }
    void Print_Upper_Triangualr_Matrix(){
        for(int i = 1; i < this->rows+1; i++){
            for (int  j = 1; j < this->cols+1; j++)
            {
                if (i <= j)
                {
                    cout << this->matrix[((j*(j-1))/2)+(i-1)] << " ";
                }
                else{
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
    void Symmeteric_Matrix(){
        this->Lower_Triangualr_Matrix();
    }
    void Set_Symmeteric_Matrix_value(int i, int j, int val){
        if(i >= j){
            this->Set_Lower_Triangualr_Matrix_Value(i,j,val);
        }
        else{
            this->Set_Lower_Triangualr_Matrix_Value(j,i,val);
        }
    }
    void Get_Symmeteric_Matrix_value(int i, int j){
        if(i >= j){
            this->Get_Lower_Triangualr_Matrix_Value(i,j);
        }
        else{
            this->Get_Lower_Triangualr_Matrix_Value(j,i);
        }
    }
    void Print_Symmeteric_Matrix(){
        for(int i = 1; i < this->rows+1; i++){
            for(int j = 1; j < this->rows+1; j++){
                if(i>=j){
                    cout << this->Get_Lower_Triangualr_Matrix_Value(i,j) << " ";
                }
                else{
                    cout << this->Get_Lower_Triangualr_Matrix_Value(j,i) << " ";
                }
            }
            cout << endl;
        }
    }
    int** Sparse_Matrix(int non_zero_elements){
        int **Sparese_Matrix = new int*[3];
            Sparese_Matrix[0] = new int[non_zero_elements];
            Sparese_Matrix[1] = new int[non_zero_elements];
            Sparese_Matrix[2] = new int[non_zero_elements+1];
            Sparese_Matrix[0][0] = this->rows;
            Sparese_Matrix[1][0] = this->cols;
            Sparese_Matrix[2][0] = non_zero_elements;
            return(Sparese_Matrix);
    }
    void Set_Sparse_Matrix_Value(int ** sparse_matrix,int i, int j, int val){
        static int index = 0;
        if(i <= this->rows && j <= this->cols && i > 0 && j > 0 && index < sparse_matrix[2][0]){
            sparse_matrix[0][index+1] = i;
            sparse_matrix[1][index+1] = j;
            sparse_matrix[2][index+1] = val;
            index++;
        }
        else{
            cout << "Wrong Index or More Than Required non Zero Elements." << endl;
        }
    }
    void Print_Sparse_Matrix(int ** sparse_matrix){
        int i, j, k = 1;
        for (int i = 1; i < this->rows; i++)
        {
            for (int j = 1; j < this->cols; j++)
            {
                if (i == sparse_matrix[0][k] && j == sparse_matrix[1][k])
                {
                    cout << " "<< sparse_matrix[2][k] << " ";
                    k++;
                }
                else{
                    cout << " 0 ";
                }
            }
            cout << endl;
        }
        
    }


    ~Matrix();
};

int main(){
    Matrix *A =  new Matrix(9,9);
    int ** SM = A->Sparse_Matrix(3);
    A->Set_Sparse_Matrix_Value(SM,1,1,10);
    A->Set_Sparse_Matrix_Value(SM,2,2,20);
    A->Set_Sparse_Matrix_Value(SM,3,3,30);
    A->Print_Sparse_Matrix(SM);
    
    return 0;
}