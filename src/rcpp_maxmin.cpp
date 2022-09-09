#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
NumericMatrix rcpp_maxmin(NumericMatrix A, NumericMatrix B){
  int n = A.nrow();
  int m = A.ncol();
  int l = B.ncol();

  NumericMatrix C(n);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < l; j++){
      NumericVector temp(n);
      for(int k = 0; k < m; k++){
        if(A(i, k) < B(k, j)){
          temp.insert(k, A(i, k));
        }else{
          temp.insert(k, B(k, j));
        }
      }
      C(i, j) = max(temp);
    }
  }
  return C;
}
