#include <iostream>
#include <iomanip>
#include <algorithm>


#define MAX 10000
#define TAM 1000
#define TER 10000

using namespace std;

int main() {

  //PRIMER EJERCICIO
  int** A;
  int *x,*y;
  clock_t start, end;
  clock_t start2, end2;
  /*Initialize A and x, assign y = 0*/
  A = new int*[MAX];
  for (int k = 0; k < MAX; k++) {
    A[k] = new int[MAX];
  }
  x = new int[MAX];
  y = new int[MAX];
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      A[i][j] = 1;
    }
    x[i] = 10;
    y[i] = 0;
  }
  /*First pair of loops*/
  int i, j;
  cout << "Primer ejercicio: \n";
  cout << " First pair of loops time: ";
  start = clock();
  for (i = 0; i < MAX; i++) {
    for (j = 0; j < MAX; j++) {
     y[i] += A[i][j] * x[j];
    }
  }
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << fixed
  << time_taken << setprecision(5);
  cout << " sec " << endl;

  /*Assing y=0*/
  for (i = 0; i < MAX; i++) {
    y[i] = 0;
  }
  /*Second pair of loops*/
  cout << " Secon pair of loops time: ";
  start2 = clock();
  for (j = 0; j < MAX; j++) {
    for (i = 0; i < MAX; i++) {
      y[i] += A[i][j] * x[j];
    }
  }
  end2 = clock();
  double time_taken2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
  cout << fixed
  << time_taken2 << setprecision(5);
  cout << " sec " << endl;

  //SEGUNDO EJERCICIO
  cout << "Segundo ejercicio\n";
  /*Inicializacion de matrices*/
  clock_t start3, end3;
  int** A2,**B2,**C2;
  A2 = new int* [TAM];
  B2 = new int* [TAM];
  C2 = new int* [TAM];
  for (i = 0; i < TAM; i++) {
    A2[i] = new int[TAM];
  }
  for (i = 0; i < TAM; i++) {
    B2[i] = new int[TAM];
  }
  for (i = 0; i < TAM; i++) {
    C2[i] = new int[TAM];
  }
  for (i = 0; i < TAM; i++) {
    for (j = 0; j < TAM; j++) {
      A2[i][j] = 2;
      B2[i][j] = 4;
    }
  }
  /*Ejecucion del producto matricial*/
  cout << "Tiempo de ejecucion de producto matricial 3 for: ";
  start3 = clock();
  for (i = 0; i < TAM; i++) {
    for (j = 0; j < TAM; j++) {
      C2[i][j] = 0;
      for (int k = 0; k < TAM; k++) {
        C2[i][j] = C2[i][j] + A2[i][k] * B2[k][j];
      }
    }
  }
  end3 = clock();
  double time_taken3 = double(end3 - start3) / double(CLOCKS_PER_SEC);
  cout << fixed
  << time_taken3 << setprecision(5);
  cout << " sec " << endl;

  /*TERCER EJERCICIO*/
  clock_t start4, end4;
  int** A3, ** B3, ** C3;
  int b = 6;
  A3 = new int* [TER];
  B3 = new int* [TER];
  C3 = new int* [TER];
  for (i = 0; i < TER; i++) {
    A3[i] = new int[TER];
  }
  for (i = 0; i < TER; i++) {
    B3[i] = new int[TER];
  }
  for (i = 0; i < TER; i++) {
    C3[i] = new int[TER];
  }
  //Inicializacion
  for (i = 0; i < TER; i++) {
    for (j = 0; j < TER; j++) {
      A3[i][j] = 2;
      B3[i][j] = 4;
      C3[i][j] = 0;
    }
  }
  //ejecucion
  cout << "Multiplicacion de matrices por bloques time: ";
  start4 = clock();
  for (int i0 = 0; i0 < TER; i0 = i0 + b)
    for (int j0 = 0; j0 < TER; j0 = j0 + b)
      for (int z0 = 0; z0 < TER; z0 = z0 + b)
        for (i = i0; i < min(i0 + b, TER); ++i)
          for ( j = j0; j < min(j0 + b, TER); ++j)
            for (int z = z0; z < min(z0 + b, TER); ++z)
              C3[i][j] = C3[i][j] + A3[i][z] * B3[z][j];
  end4 = clock();
  double time_taken4 = double(end4 - start4) / double(CLOCKS_PER_SEC);
  cout << fixed
  << time_taken4 << setprecision(5);
  cout << " sec " << endl;

  return 0;
}
