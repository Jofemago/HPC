/*Multiplicacion de matrices de manera secuencial...*/

#include<bits/stdc++.h>


using namespace std;



void _multMat( vector<vector<int>> &A, vector<vector<int>> B, vector<vector<int>> &C, int num){
    /*multiplicacion de matrices de manera serial*/
    #pragma omp for num_threads(5)
    
        //multiplicación 
        for(int i = 0; i < num; i++)
            for(int j = 0; j < num; j++)
                for(int k = 0 ; k < num; k++)
                    C[i][j] += A[i][k] * B[k][j];
    
    
}


void multMat( vector<vector<int>> &A, vector<vector<int>> B, vector<vector<int>> &C, int num){
    /*multiplicacion de matrices de manera serial*/
    for(int i = 0; i < num; i++)
        for(int j = 0; j < num; j++)
            for(int k = 0 ; k < num; k++)   
                C[i][j] += A[i][k] * B[k][j];
}


void relleno(vector<vector<int>> &R, int num){
    
for(size_t i = 0; i < num; i++)
   {
       for(size_t j = 0; j < num; j++){
           
           R[i][j] = rand()%10;
       }
    
   }
}

void mostrar(vector<vector<int>> &R, int num){

    for(size_t i = 0; i < num; i++)
   {
       for(size_t j = 0; j < num; j++){
           cout << R[i][j] << " ";
       }
       cout << endl;
   }
   
}

int main(int argc, char *argv[]){
    
    int num = 0;
    try
    {
        num = stoi(argv[1]);
    }
    catch(const exception& e)
    {

        cerr << "lo siento falle: "<< e.what() << '\n';
    }
    
    vector<vector<int>> A(num, vector<int> (num));
    vector<vector<int>> B(num, vector<int> (num));
    vector<vector<int>> R(num, vector<int> (num));
    srand(time(nullptr));
    relleno(A, num);
    //mostrar(A,num);
    //cout << "X" << endl;
    relleno(B, num);
    //mostrar(B,num);
    //cout << "=" << endl;
    /*
    //calculo del tiempo
    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();

    multMat(A, B, R, num);
    //mostrar(R, num);

    end = std::chrono::system_clock::now();
    double time = std::chrono::duration_cast<std::chrono::milliseconds>
                             (end-start).count();

    cout << time << ","; 
    */

    vector<vector<int>> R_openmp(num, vector<int> (num));
    multMat(A, B, R, num);
    multMat(A, B, R_openmp, num);

    mostrar(R, num);
    mostrar(R_openmp, num);
    //cout << A << endl;
    //cout<<num << endl;

    return 0;
}

