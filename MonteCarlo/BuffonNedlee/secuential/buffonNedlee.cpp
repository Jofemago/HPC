
#include<bits/stdc++.h>


using namespace std;

using puntos = vector<double>;
using apuntador = vector<bool>;

double pi =  M_PI;
double randiasDivGrades  = pi/180.0;


std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
//std::uniform_real_distribution<> dis(-1.0, 1.0);

void launchNedlee(int n, int t, puntos &xs, puntos &angulos, puntos &radians){

    std::uniform_real_distribution<> disX(0, t/2);
    std::uniform_real_distribution<> disAng(0, 90);

    for(int i = 0; i < n; ++i){
        xs[i] = disX(gen);
        angulos[i] = disAng(gen);
        radians[i] = angulos[i] * randiasDivGrades;
        //cout << "distancia en X: "<< xs[i]<< endl;
        //cout << "valor del angulo: " << angulos[i]<< endl;
        //cout << endl;
    }

}


void simulation(int n, int t, int d, puntos &xs, puntos &angulosradians){ 
    double enlinea = 0.0;

    for (size_t i = 0; i < n; i++)
    {
        if(xs[i] <= (d/2.0) * sin(angulosradians[i]))
            enlinea++;
    }
    
    double picalculate = 2 * ((double(n) * double(d))/(double(t) * enlinea));
    //cout << "value of pi: " << picalculate << endl;

}

int main(int argc, char *argv[]){

    int n = 0, t = 0, d = 0;
    try
    {
        n = stoi(argv[1]);//argv 0 , cantidad de agujas
        t = stoi(argv[2]);//argv 1, separacion entre lineas
        d = stoi(argv[3]);//argv 2, tamaño de las agujas
        
    }
    catch(const exception& e)
    {
        std::cerr << "los valores ingresados estan mal" << '\n';
    }

    assert(d < t);

    puntos xs = puntos(n, 0.0 );
    puntos angulos = puntos(n, 0.0 );
    puntos angulosRadians = puntos(n,0.0);

    

    launchNedlee(n,t, xs, angulos, angulosRadians);
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    
    simulation(n,t,d,xs,angulosRadians);
    
    end = std::chrono::system_clock::now();
    double time = std::chrono::duration_cast<std::chrono::nanoseconds>
                           (end-start).count();

    cout << time<<",";
    //cout << "los valores son: " << n << t << d << endl;


    return 0;
}