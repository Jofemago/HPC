#include<iostream>
#include<string>
using namespace std;

int tc = 0;
int ts = 0;

__host__ int* MakeCarretera(){
    //srand(time(NULL));
    int *res  = (int *)malloc((tc + 1) * sizeof(int));
    for(int i = 0; i < tc ; i++){

        res[i] = (rand() % 10) % 2 ;
    }
    return res;
}

__host__ void MostrarCarretera(int* crt){

    for(int i = 0; i < tc; i++){

        cout << crt[i] << " ";
    }
    cout << "\n";

}

__global__ void prueba(int *ctr,int n){

  //cout << to_string(blockIdx.x) + "\n";
    ctr[blockIdx.x] +=2;
    /*
    int index = threadIdx.x +  blockIdx.x * blockDim.x;
    if (index < n)
      ctr[index] +=1;*/
    //threadIdx.x
}

int main(int argc, char *argv[]) {
  int *carretera, *res;
  int *d_carretera;
  int size = tc + 1;
  int sizeint = size * sizeof(int);
  try{

      tc = stoi(argv[1]);// el tamaño de la carretera
      ts = stoi(argv[2]);// el numero de iteraciones
  }
  catch(const exception& e)
  {

      cout << "No se ingresaron variables, no se hara nada \n\t tc : tamaño de la carreter entero \n\t ts numero de iteraciones que va realizar la simulacion entero"<< '\n';
  }


  if (tc != 0 && ts != 0)  {
    carretera = MakeCarretera();
    MostrarCarretera(carretera);

    //allocate space for devide copies of carretera
    cudaMalloc((void **) &d_carretera, sizeint);


    //copiando datos al device
    cudaMemcpy(d_carretera, carretera, sizeint ,cudaMemcpyHostToDevice);
    //int hilos = 10;
    // lanzar una funcion
    //prueba<<<tc/hilos, hilos >>>(carretera, tc);
    prueba<<<1, tc >>>(carretera, tc);
    //copiando resultados desde el device al host
    cudaMemcpy(carretera, d_carretera, sizeint, cudaMemcpyDeviceToHost);
    MostrarCarretera(d_carretera);
    //liberando el espacio
    free(carretera);
    cudaFree(d_carretera);

  }

  return 0;

}
