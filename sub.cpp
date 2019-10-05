/*

Este algoritmo fue obtenido de: https://www.geeksforgeeks.org/longest-common-substring-dp-29/
Tipo de programacion: algoritmo dinamico
Complejidad del algoritmo: O(m*n)


 */
 #include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void EncontrarSubstring(char* subA, char* subB, int x, int y){

  int subT[x+1][y+1];   //donde se almacenarán los valores
  int tam = 0;          //inicio contador
  int reng, col;

  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= y; j++) {
      if (i == 0 || j == 0) {
        subT[i][j] = 0;

      }
        else if (subA[i-1] == subB[j-1]) {
          subT[i][j] = subT[i-1][j-1] + 1;
          if (tam < subT[i][j]) {
            tam = subT[i][j];
            reng = i;
            col = j;
          }
        }
        else{
          subT[i][j] = 0;
        }
    }
  }

  if (tam == 0) {
    cout << "No hay un substring en común";
    return;
  }

  char* subFinal = (char*)malloc((tam+1) * sizeof(char));

  while (subT[reng][col] != 0) {
    subFinal[--tam] = subA[reng - 1];

    reng --;
    col--;
  }

  int subFinalNo = strlen(subFinal);

  cout << "El substring es '" << subFinal<< endl;
};

int main() {

  char subA[] = "Charlie de la garza macias";
  char subB[] = "charlie es un genio";

  int x = strlen(subA);
  int y = strlen(subB);

  EncontrarSubstring(subA, subB, x, y);

  return 0;
}