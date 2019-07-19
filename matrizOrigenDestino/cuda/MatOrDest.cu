#include<iostream>

usign namespace std;



int main(int argc, char *argv[]) {

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
    cout << tc << " " << ts <<< endl;
  }

}
