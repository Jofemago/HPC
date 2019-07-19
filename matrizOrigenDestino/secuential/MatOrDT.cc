
#include <iostream>
#include <stdlib.h>

#include<bits/stdc++.h>

using namespace std;

//funciones prototipo
int* MakeCarretera();
void MostrarCarretera(int *);
int* fillCarreteraZero();
int* run(int*);
void simulation(int*);

int tc = 0;
int ts = 0;

int main(int argc, char *argv[]){

    int *carretera;
    try{
    
        tc = stoi(argv[1]);// el tamaño de la carretera
        ts = stoi(argv[2]);// el numero de iteraciones
    }
    catch(const exception& e)
    {

        cout << "No se ingresaron variables, no se hara nada \n\t tc : tamaño de la carreter entero \n\t ts numero de iteraciones que va realizar la simulacion entero"<< '\n';
    }

    if (tc != 0 && ts != 0)  {

        //se carga la carretera de manera aleatorea
        carretera = MakeCarretera();
        //MostrarCarretera(carretera);
        //ejecucion del programa
        //cout << "se empiezan las iteraciones" << endl;
        std::chrono::time_point<std::chrono::system_clock> start, end;

        start = std::chrono::system_clock::now();
        
        simulation(carretera);
        end = std::chrono::system_clock::now();
            double time = std::chrono::duration_cast<std::chrono::nanoseconds>
                           (end-start).count();

        cout << time<<","; 

    }

}

void simulation(int* carretera){
    while(ts){

            carretera = run(carretera);
            //MostrarCarretera(carretera);
            //cout << "la velocidad media de iteracion " << double(carretera[tc])/double(tc) << endl;
            ts--;
        }
}


int* run(int* crt) {

    int *newcrt = fillCarreteraZero();
    int velit = 0;

    for(int i = 0; i < tc ; i++) {

        int act = i;
        int sgt = i + 1;
        if( act == tc - 1) {
            sgt = 0;
        }

        if( crt[act] != 0) { // si en mi posicion no hay vehiculo, entonces nada avanza

            if( crt[act] == 1){
                if(crt[sgt] == 0) {
                    newcrt[sgt] = 1;// se mueve un vehiculo
                    velit++;
                }else{
                    newcrt[act] = 1;
                }
            }
        }

    }
    newcrt[tc] = velit;
    return newcrt;
}

void MostrarCarretera(int* crt){

    for(int i = 0; i < tc; i++){

        cout << crt[i] << " ";
    }
    cout << "\n";

}

int* fillCarreteraZero(){

    int *res  = (int *)malloc((tc + 1) * sizeof(int)); 
    for(int i =  0; i < tc ; i++) {
        res[i] = 0;
    }
    return res;
}

int* MakeCarretera(){
    //srand(time(NULL)); 
    int *res  = (int *)malloc((tc + 1) * sizeof(int)); 
    for(int i = 0; i < tc ; i++){
        
        res[i] = (rand() % 10) % 2 ;
    }
    return res;
}

