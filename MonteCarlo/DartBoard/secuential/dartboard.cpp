/*Multiplicacion de matrices de manera secuencial...*/

#include<bits/stdc++.h>


using namespace std;

std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
std::uniform_real_distribution<> dis(-1.0, 1.0);

double dartboard(int dardos){

  assert(dardos > 0);

  //double x = dis(gen);
  int hits = 0;

  for(int k = 0; k < dardos ; ++k){//mejora al cache line.

    double x = dis(gen);
    double y = dis(gen);

    if( x*x + y*y < 1.0){
      ++hits;

    }
  }
  //cout << "hits " << hits<<",";
  //cout << "el numero de dardos: "<< dardos << endl;
  double res = 4.0 * hits * 1.0/dardos;
  //cout << "el resultado es: " << res << endl;

  return res;



}

int main(int argc, char *argv[]){

  int dardos = 0;
  try{

      dardos = stoi(argv[1]);
      //cout << "numero de dardos establecido en: " << dardos << endl;
  }
  catch(const exception& e)
  {

      cerr << "lo siento falle: "<< e.what() << '\n';
  }
  //double x =
  //cout << x<< endl;


  std::chrono::time_point<std::chrono::system_clock> start, end;

  start = std::chrono::system_clock::now();

  dartboard(dardos);

  end = std::chrono::system_clock::now();
  double time = std::chrono::duration_cast<std::chrono::nanoseconds>
                           (end-start).count();

  cout << time<<",";


  return 0;
}
