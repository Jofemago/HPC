#include<bits/stdc++.h>


using namespace std;

void relleno(vector<vector<int>> &R, int num){
    
for(size_t i = 0; i < num; i++)
   {
       for(size_t j = 0; j < num; j++){
           
           R[i][j] = rand()%10;
       }
    
   }
}


void multMat( vector<vector<int>> &A, vector<vector<int>> B, vector<vector<int>> &C, int num, int fila){
    /*multiplicacion de matrices de manera serial*/
    //cout << "hilo " << fila << endl;
    assert(fila < num);
    //for(int i = fila; i < num; i++)
    for(int j = 0; j < num; j++)
        for(int k = 0 ; k < num; k++)
            C[fila][j] += A[fila][k] * B[j][k];

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

void transponer(vector<vector<int>> &B, vector<vector<int>> &T, int num){

        for(int i = 0; i < num; i++)
            for(int j = 0; j < num; j++)
                T[i][j] = B[j][i];
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


    //variables para medicion de tiempo
    

    vector<vector<int>> A(num, vector<int> (num));
    vector<vector<int>> B(num, vector<int> (num));
    vector<vector<int>> R(num, vector<int> (num));
    vector<vector<int>> Btransp(num, vector<int> (num));
   
    relleno(A, num);
    relleno(B, num);
    transponer(B, Btransp, num);
    /*mostrar(A,num);
    cout << "X" << endl;
    
    mostrar(B,num);
    cout << "=" << endl;
    */
   //unsigned t0, t1;
    
    //creacion de hilos
    srand(time(nullptr));
    vector<thread> th;
    //thread th[num];
    //operacion de la respuesta de forma concurrente
    
    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    for(int i = 0; i < num; i++)           
        th.push_back(thread(multMat,ref(A), ref(B), ref(R), num, i));
          
    for(int i = 0; i < num; i++)
        th[i].join();

    end = std::chrono::system_clock::now();
    double time = std::chrono::duration_cast<std::chrono::milliseconds>
                             (end-start).count();
   

    cout << time << ","; 
    /*
    mostrar(R, num);
    */
    return 0;


}
