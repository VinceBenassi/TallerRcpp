#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]

NumericMatrix rcpp_cbind(NumericVector A, NumericMatrix B){
  int filas = B.nrow();
  int columnas = B.ncol();
  int largoVector = A.size();

  for(int i=0; i < filas; i++){
    for (int j=0; j < columnas; j++){
      if(largoVector == filas){
        NumericMatrix C(filas, columnas+1);
        NumericVector newVector;

        for(int k = 0; k < largoVector; k++){
          newVector = B.row(k);
          newVector.push_back(A(k));
          C.row(k) = newVector;
        }
        return C;
      }
      Rcout << "\n";
    }
  }
  return 1;
}
