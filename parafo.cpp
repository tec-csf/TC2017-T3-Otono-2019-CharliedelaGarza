/*

Este algoritmo fue obtenido de: https://www.geeksforgeeks.org/word-wrap-problem-dp-19/
Tipo de programacion: ávida
Complejidad del algoritmo: O(n) 


 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

float reducirCosto(float red, float sizeI, int j, int i);
float ampliarCosto(float amp, float sizeI, int j, int i);

int main(int argc, const char * argv[]) {
    
    vector<string> text = {"Hola", "mi", "compa", "gracias", "por la tarea"};
    vector<int> longWord;
    vector<string> line;
    
    float longLine = 27;
    float word = 0;
    float longWordAmpl = 0;
    
    float sizeI = 1;
    float sobrante;
    
    int i = 0;
    int j;
    
    float red;
    float amp;
    
    bool foo = true;
    
    for (int i = 0; i < text.size(); i++)
    {
        longWord.push_back( int(text[i].length()) );
    }
    
    for (j = 0; j < text.size(); j++)
    {
        if (foo)
        {
            i = j;
            foo = false;
            line.clear();
            word = 0;
        }
        
        word += longWord[j];
        longWordAmpl = word + ((j - i) * sizeI);
        
        if (longWordAmpl > longLine)
        {
            sobrante = longWordAmpl - longLine;
            red = sizeI - (sobrante / (j - i));
            amp = sizeI + (longLine - ( (word - longWord[j]) + (sizeI * (j - i - 1) ) ) ) / (j - i - 1);
            
            if ( ampliarCosto(amp,sizeI,j,i) > reducirCosto(red, sizeI,j,i) && red > 0 )
            {
                line.push_back(text[j]);
                
                for (int i = 0; i < line.size(); i++)
                {
                    cout << line[i] << " ";
                }
                
                cout << " " <<  " ---> reducción de : " << red << " mm." << endl;
                foo = true;
            }
            else {
                for (int i = 0; i < line.size(); i++)
                {
                    cout << line[i] << " ";
                }
                
                cout << " " << " ---> amplitud de : " << amp << " mm." << endl;
                j--;
                foo = true;
            }
        }
        line.push_back(text[j]);
    }
    
    for (int i = 0; i < line.size(); i++)
    {
        std::cout << line[i] << " ";
    }
    
    cout << endl;
    
}



float reducirCosto(float red, float amplitudI, int j, int i)
{
    return ( fabs(red - amplitudI) * (j - i) );
}

float ampliarCosto(float amp, float amplitudI, int j, int i)
{
    return ( fabs(amp - amplitudI) * (j - i - 1) );
}