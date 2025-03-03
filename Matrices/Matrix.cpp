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

    ~Matrix();
};

int main(){
    Matrix *A =  new Matrix(3,3);
    return 0;
}