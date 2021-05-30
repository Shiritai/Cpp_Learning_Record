#include "matrixSum.h"

// Calculate row sum first
int rowSum(int array[][COL]){
  int sum=0;
  for(int i=0; i<ROW; i++)
    for(int j=0; j<COL; j++)	// row sum
      sum+=array[i][j];
  return sum;
}

// Calculate column sum first
int colSum(int array[][COL]){
  int sum=0;
  for(int j=0; j<COL; j++)
    for(int i=0; i<ROW; i++)	// col sum
      sum+=array[i][j];
  return sum;
}
