#include <bits/stdc++.h>


using namespace std;



void simple(int n, double *a, double *b){

  int i;
  #pragma omp parallel for
    for(i = 1; i < n; i++){
      b[i] = (a[i] + a[i - 1])/2.0;
      string str = "";
      //string c = string(i);
      str += to_string(i);
      str +=" resultado b[] : ";
      str += '\n';
      str += to_string(b[i]);


      cout <<str;
}

}

 int main(){
   int n = 5;
   double *a = nullptr, *b = nullptr;
   a = new double[n];
   b = new double[n];



   simple(n,a,b);

   return 0;
 }
