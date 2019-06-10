#include<omp.h>
#include<iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int p, th_id;
    p= omp_get_num_procs() * 2;
    cout << "procesos: "<< p << endl;
    //omp_set_num_threads(p);
    #pragma omp parallel num_threads(p) private(th_id)
    {
        th_id = omp_get_thread_num();

        cout << "se esta ejecutando el hilo: "+ to_string(th_id) + '\n';
    }

    return 0;
}
