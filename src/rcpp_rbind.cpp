#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix rcpp_rbind(NumericVector A, NumericMatrix B){
  int filas = B.nrow();
  int columnas = B.ncol();
  int largoVector = A.size();

  for(int i=0; i < filas; i++){
    for (int j=0; j < columnas; j++){
      if(largoVector == columnas){
        NumericMatrix C(filas+1, columnas);
        NumericVector newVector;

        for(int k = 0; k < largoVector; k++){
          newVector = B.column(k);
          newVector.push_back(A(k));
          C.column(k) = newVector;
        }
        return(C);
      }
      Rcout << "\n";
    }
  }
  return 1;
}
