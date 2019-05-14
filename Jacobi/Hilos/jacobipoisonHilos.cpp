#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include <chrono>
#include<iostream>
//#include<bits/stdc++.h>



using namespace std;
//#include <omp.h>
/* --
 * Do nsweeps sweeps of Jacobi iteration on a 1D Poisson problem
 *
 *    -u'' = f
 *
 * discretized by n+1 equally spaced mesh points on [0,1].
 * u is subject to Dirichlet boundary conditions specified in
 * the u[0] and u[n] entries of the initial vector.
 * 
 * 
 */
void imprimir(string a, double *u, int n){


    cout<<a<<endl;
    for(int i=0;i<=n;i++){

        
        cout<<u[i]<<" ";
    }
}


void iteratetemp(int n, int h2,  double *u, double *utmp, double *f){

    /* Old data in u; new data in utmp */
        for (int i = 1; i < n; ++i){
            utmp[i] = (u[i-1] + u[i+1] + h2*f[i])/2;
        }
        //imprimir("iteracion funcion: ", utmp, n);
}


void iterateU(int n, int h2,  double *u, double *utmp,double *f){

    /* Old data in utmp; new data in u */
        for (int i = 1; i < n; ++i){
            u[i] = (utmp[i-1] + utmp[i+1] + h2*f[i])/2;
        }
        //imprimir("iteracion funcion: ", utmp, n);
}


void jacobi(int nsweeps, int n, double* u, double* f){
    double h  = 1.0 / n;
    double h2 = h*h;
    double* utmp;
    utmp = new double[n+1];

    /* Fill boundary conditions into utmp */
    utmp[0] = u[0];
    utmp[n] = u[n];

    cout << "h2 "<< h2 << endl;
    imprimir("inicio f: ", f, n);
    imprimir("inicio: ", utmp, n);
    imprimir("inicio: ", u, n);
    for (int sweep = 0; sweep < nsweeps; sweep += 2) {
        
        iteratetemp(n,h2,u,utmp,f);
        iterateU(n,h2,u,utmp,f);
        


/*
       
        for (int i = 1; i < n; ++i){
            utmp[i] = (u[i-1] + u[i+1] + h2*f[i])/2;
        }

      
        for (int i = 1; i < n; ++i){
            u[i] = (utmp[i-1] + utmp[i+1] + h2*f[i])/2;
}*/


    }

    imprimir("fin: ", utmp, n);
    imprimir("fin: ", u, n);

    delete [] utmp;
}

/*

void write_solution(int n, double* u, const char* fname){
    double h = 1.0 / n;
    FILE* fp = fopen(fname, "w+");
    for (int i = 0; i <= n; ++i){
        fprintf(fp, "%g %g\n", i*h, u[i]);
    }
    fclose(fp);
}

void writeTime(float elapsed, int valueK, int len){
	FILE *f = fopen("timesc++Secuential.txt","a+");//write at end of file and set result, append
	fprintf(f,"%ld	%ld	%.9f\n", valueK, len, elapsed);
	fclose(f);
}

*/

int main(int argc, char** argv){
    if(argc < 2){
		printf("There should be 3 or 2 arguments! (outputfile is optional)-> nameexecute.exe $n $steps $outputfile\n");
		exit(1);
	}
    int n, nsteps;
    double* u;
    double* f;
    double h;
    char* fname;

    /* Process arguments */
    n      = (argc > 1) ? std::stoll(argv[1], nullptr) : (int)100;
    nsteps = (argc > 2) ? std::stoll(argv[2], nullptr) : (int)100;
    fname  = (argc > 3) ? argv[3] : NULL;
    h      = 1.0/n;

    /* Allocate and initialize arrays */
    u = new double[n+1];
    f = new double[n+1];
    memset(u, 0, (n+1) * sizeof(double));
    for (int i = 0; i <= n; ++i){
        f[i] = i * h;
    }

    /* Run the solver */
    // printf("nsteps %ld\n",nsteps);
    //auto startTime=std::chrono::high_resolution_clock::now();
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    jacobi(nsteps, n, u, f);


    end = std::chrono::system_clock::now();
    double time = std::chrono::duration_cast<std::chrono::nanoseconds>
    (end-start).count();
    //auto endTime=std::chrono::high_resolution_clock::now();
    //std::chrono::duration<float>  elapsed = endTime - startTime;
	//writeTime(elapsed.count(), n, nsteps);
    //get_time(&tend);

    /* Run the solver */
    /*printf("n: %d\n"
           "nsteps: %d\n"
           "Elapsed time: %g s\n",
           n, nsteps, timespec_diff(tstart, tend));
*/
    /* Write the results
    if (fname){
        write_solution(n, u, fname);
    }
    */
    cout << time << ",";

    delete [] f;
    delete [] u;
    return 0;
}
