/*--------------------------------------------------------------------------------
 * Dato de Entrada: tam (int), trabajamos con una matriz dinamica pero cuadrada
 * Dato de Salida: matriz, elMayor, suma de los elementos de la diagonal principal
 *                 suma de elementos ubicados por encima de la diagonal
 ---------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>

using namespace  std;

void llenarDatos( int * *pMat, int tam);
void imprimirMatriz(  int * *pMat, int tam);
int hallarElMenor(int * *pMat, int tam);
int sumaDeDiagonal(  int * *pMat, int tam);
int sumaSuperior( int * *pMat, int tam);

int main()
{ int tam;
   int * *pMatriz=nullptr;

   srand(time(nullptr));
   do{
       cout << "Tamanio : ";
       cin >> tam;
   }while(tam<4);

   //--- dimensionamos la matriz
   pMatriz = new int*[tam];
   for(int f=0; f<tam; f++)
       pMatriz[f] = new int[tam];
   llenarDatos(pMatriz,tam);
   cout << "\n";
   imprimirMatriz(pMatriz,tam);
   cout << "\n";
   cout << "El elemento mas pequenno de la matriz es: " << hallarElMenor(pMatriz, tam) << "\n";
   cout << "La suma de los elementos de la diagonal principal es : "  << sumaDeDiagonal(pMatriz, tam) << "\n";
   cout << "Las suma de los elementos que estan por encima de la diagonal :" << sumaSuperior(pMatriz,tam) << "\n";
   //--- liberamos es espacio de memoria asignado para la matriz
   for(int f=0; f<tam; f++)
       delete []pMatriz[f];
   delete []pMatriz;
   pMatriz = nullptr;
    return 0;
}

void llenarDatos( int * *pMat, int tam)
{
    for(int f=0; f<tam; f++)
        for(int c=0; c<tam; c++)
            pMat[f][c] = rand()%99 + 1;
}

void imprimirMatriz(  int * *pMat, int tam)
{
    for(int f=0; f<tam; f++){
        for(int c=0; c<tam; c++)
            cout << setw(4) << pMat[f][c];
        cout << "\n";
    }
}

int hallarElMenor(int * *pMat, int tam)
{
  int menor = pMat[0][0];
  for(int f=0; f<tam; f++)
      for( int c=0; c<tam; c++)
          if(pMat[f][c] < menor)
              menor = pMat[f][c];
  return menor;
}

int sumaDeDiagonal(  int * *pMat, int tam)
{
    int suma = 0;
    for (int f = 0; f < tam; f++)
        suma = suma + pMat[f][f];
    return suma;
}

int sumaSuperior( int * *pMat, int tam)
{
    int suma =0;
    for(int f=0; f<tam-1; f++)
        for(int c=f+1; c<tam; c++)
            suma += pMat[f][c];
    return suma;
}