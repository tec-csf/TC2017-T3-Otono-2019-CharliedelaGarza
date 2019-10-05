/*
Este algoritmo fue obtenido de: https://www.geeksforgeeks.org/number-of-refills-to-complete-the-journey-of-n-km/
Tipo de programacion: ávida
Complejidad del algoritmo: O(n)
 */
#include <iostream>
#include <stdio.h>

using namespace std;

int ParadaForzosa(int N, int K, int M, int compulsory[]) 
{ 
    int count = 0; 
    int i = 0; 
    int distCovered = 0; 
  
    // While we complete the whole journey. 
    while (distCovered < N && i < M) { 
        // If must visited petrol pump lie 
        // between distCovered and distCovered+K. 
        if (compulsory[i+1] > (distCovered + K)) {
            distCovered = compulsory[i]; 
            i++; 
            count++; 
            
        }else{
            i++;
        }
             
  
         
    }
    return count; 
    
} 


int main() {

  int recorrido = 200;    //distancia total a recorrer
  int distiaSinParar = 50;         //distancia que puede recorrer entre gasolineras
  int paradas = 4;      //cantidad de gasolineras en las que deberá parar
  int petrol;       //valor de las paradas

  int gas[] = {50,100,150,180};
  


  
  cout << ParadaForzosa(recorrido, distiaSinParar, paradas, gas) << endl; 

  return 0;
}