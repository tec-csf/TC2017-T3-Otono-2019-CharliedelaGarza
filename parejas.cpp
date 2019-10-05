/*

Este algoritmo fue obtenido de: https://www.geeksforgeeks.org/stable-marriage-problem/
Tipo de programacion: backtracking
Complejidad del algoritmo: O(n^2) 

 Referencia: GeeksForGeeks
 */



#include <iostream>
#include <vector>
using namespace std;

bool mejorHombre(vector<vector<int>> preferencia, int hombre, int mujer, int hombre1, int n);
void asignarParejas(vector<vector<int>> preferencia, int columnas);
bool mejorHombre(vector<vector<int>> preferencia, int hombre, int mujer, int otroHombre, int columnas)
{
    for (int i = 0; i < columnas; i++)
    {
        if (preferencia[mujer][i] == otroHombre)
        {
            return true;
        }
        if (preferencia[mujer][i] == hombre)
        {
            return false;
        }
        
    }
    
    return false;
}

void asignarParejas(vector<vector<int>> preferencia, int columnas)
{
    vector<int> parejaMujeres;
    vector<bool> asignadosH;
    
    for (int i = 0; i < columnas; i++)
    {
        parejaMujeres.push_back(-1);
        asignadosH.push_back(false);
    }
    
    int solteros = columnas;
    
    while (solteros > 0)
    {
        int hombre=0;
        
        for (int i = 0; i < columnas; i++)
        {
            if (asignadosH[i] == false)
            {
                hombre = i;
                i = columnas;
            }
        }
        
        for (int i = 0; (i < columnas) && (asignadosH[hombre] == false); i++)
        {
            int mujer = preferencia[hombre][i];
            if (parejaMujeres[mujer - columnas] == -1)
            {
                parejaMujeres[mujer - columnas] = hombre;
                asignadosH[hombre] = true;
                solteros--;
            }
            
            else
            {
                int otroHombre = parejaMujeres[mujer - columnas];
                
                if (mejorHombre(preferencia, hombre, mujer, otroHombre, columnas) == false)
                {
                    parejaMujeres[mujer - columnas] = hombre;
                    asignadosH[hombre] = true;
                    asignadosH[otroHombre] = false;
                }
            }
        }
    }
    
    for (int i = 0; i < columnas; i++)
    {
        cout << "Mujer " << i + columnas << " asignada al hombre " << parejaMujeres[i] << endl;
    }
}


int main()
{
    int columnas = 4;
    vector<vector<int>> preferencia(2 * columnas, vector<int>(columnas));
    
    preferencia =
    {
          
        {5, 4, 6, 7}, 
        {4, 5, 6, 7}, 
        {4, 5, 6, 7}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        
    };
    
    asignarParejas(preferencia, columnas);
}