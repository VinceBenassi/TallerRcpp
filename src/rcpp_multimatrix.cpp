#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
void rcpp_multimatrix(NumericMatrix A, NumericMatrix B){
  int filas = A.nrow();
  int columnasA = A.ncol();
  int columnasB = B.ncol();

  // Multiplicación
  for (int i=0; i<filas; i++){
    for (int j=0; j<columnasB; j++){
      NumericMatrix C(filas, columnasB);
      C(i, j) = 0;
      for(int k=0; k<columnasA; k++){
        C(i, j) = C(i, j) + (A(i, k) * B(k, j));
      }
      Rcout << C(i, j) << " ";
    }
    Rcout << "\n";
  }
}
