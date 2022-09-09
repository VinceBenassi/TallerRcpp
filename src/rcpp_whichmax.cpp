#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
DataFrame rcpp_whichmax(NumericMatrix A){
  DataFrame df(A.nrow());
  int mayor = A(0, 0);
  int filas = A.nrow();
  int columnas =A.ncol();
  int indice = 0;

  for(int i=0; i < filas; i++){
    for (int j=0; j < columnas; j++){
      if(A(i, j) > mayor){
        mayor = A(i, j);
        indice = 0;
        df.erase(0, df.size());
        IntegerVector max = IntegerVector::create(i+1, j+1);
        df.insert(indice, max);
        indice += 1;
      }
      else if(A(i, j) == mayor){
        IntegerVector max = IntegerVector::create(i+1, j+1);
        df.insert(indice, max);
        indice += 1;
      }
    }
  }
  return df;
}
