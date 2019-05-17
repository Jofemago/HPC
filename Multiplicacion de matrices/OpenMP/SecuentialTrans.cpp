/*Multiplicacion de matrices de manera secuencial...*/

#include<bits/stdc++.h>


using namespace std;


void multMatTrans( vector<vector<int>> &A, vector<vector<int>> B, vector<vector<int>> &C, int num){
    /*multiplicacion de matrices de manera serial*/
    for(int i = 0; i < num; i++)
        for(int j = 0; j < num; j++)
            for(int k = 0 ; k < num; k++)
                C[i][j] += A[i][k] * B[j][k];
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
   cout << endl;
   
}

void transponer(vector<vector<int>> &B, vector<vector<int>> &T, int num){

        for(int i = 0; i < num; i++)
            for(int j = 0; j < num; j++)
                T[i][j] = B[j][i];
}

int main(int argc, char *argv[]){
    
    int num = 0;
    try{
    
        num = stoi(argv[1]);
    }
    catch(const exception& e)
    {

        cerr << "lo siento falle: "<< e.what() << '\n';
    }
    
    vector<vector<int>> A(num, vector<int> (num));
    vector<vector<int>> B(num, vector<int> (num));
    vector<vector<int>> Btransp(num, vector<int> (num));
    vector<vector<int>> R(num, vector<int> (num));
   
    srand(time(nullptr));
    relleno(A, num);

    //mostrar(A,num);
    //cout << "X" << endl;

    relleno(B, num);

    //mostrar(B,num);
    //cout << "=" << endl;

    transponer(B, Btransp, num);

    //mostrar(Btransp,num);
    
    //mostrar(R, num);
    
    //calculo del tiempo
    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();

    multMatTrans(A, Btransp, R, num);
    //mostrar(R, num);

    end = std::chrono::system_clock::now();
    double time = std::chrono::duration_cast<std::chrono::milliseconds>
                             (end-start).count();

    cout << time << ","; 

    //cout << A << endl;
    //cout<<num << endl;
    
    return 0;
}

