
#include<bits/stdc++.h>


using namespace std;

using puntos = vector<double>;

std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
//std::uniform_real_distribution<> dis(-1.0, 1.0);

void launchNedlee(int n, int t, puntos &xs, puntos &angulos){

    std::uniform_real_distribution<> disX(0, t/2);
    std::uniform_real_distribution<> disAng(0, 90);

    for(int i = 0; i < n; ++i){
        xs[i] = disX(gen);
        angulos[i] = disAng(gen);
        cout << "distancia en X: "<< xs[i]<< endl;
        cout << "valor del angulo: " << angulos[i]<< endl;
        cout << endl;
    }

}

int main(int argc, char *argv[]){

    //argv 0 , cantidad de agujas
    //argv 1, separacion entre lineas
    //argv 2, tamaño de las agujas

    int n = 0, t = 0, d = 0;
    try
    {
        n = stoi(argv[1]);
        t = stoi(argv[2]);
        d = stoi(argv[3]);
        
    }
    catch(const exception& e)
    {
        std::cerr << "los valores ingresados estan mal" << '\n';
    }

    assert(d < t);
    puntos xs = puntos(n, 0.0 );
    puntos angulos = puntos(n, 0.0 );

    launchNedlee(n,t, xs, angulos);

    
    //cout << "los valores son: " << n << t << d << endl;


    return 0;
}