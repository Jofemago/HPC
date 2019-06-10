/*Multiplicacion de matrices de manera secuencial...*/

#include<bits/stdc++.h>
#include <omp.h>

using namespace std;

std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
std::uniform_real_distribution<> dis(-1.0, 1.0);




double dartboard(int dardos){

  assert(dardos > 0);

  //double x = dis(gen);
  //int hits = 0;
  int th_id;
  int p= omp_get_num_procs() * 2;
  //cout << "procesos: "<< p << endl;
  double res = 0.0;
  vector<int> hits(p);

  /*cout << "tamaño hits: "<< hits.size()<< endl;
  for(int &n: hits){
    cout << n << endl;
  }
  */
  int ejec = 0;

  #pragma omp parallel for num_threads(p) private(th_id,ejec)
    for(int k = 0; k < dardos ; ++k){//mejora al cache line.


      double x = dis(gen);
      double y = dis(gen);
      th_id = omp_get_thread_num();



      if( x*x + y*y < 1.0){
        ++hits[th_id];
      }

    }

  int hitsresult = 0;
  for(int i = 0; i < hits.size(); ++i){

    hitsresult += hits[i];
  }



  //cout << "hitsresult " << hitsresult << endl;

  //cout << "el numero de dardos: "<< dardos << endl;
  res = 4.0 * hitsresult * 1.0/dardos;
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
  double time = std::chrono::duration_cast<std::chrono::milliseconds>
                           (end-start).count();

  cout << time << ",";


  return 0;
}
