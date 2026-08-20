#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
/*
Estas son las funciones básicas de std::vector en C++ agrupadas por su propósito. La mayoría requiere incluir la librería <vector>, y las funciones de búsqueda requieren <algorithm>.
## Inserción (Agregar elementos)

* push_back(valor): Agrega un elemento al final del vector de forma automática.
* emplace_back(argumentos): Construye un elemento directamente al final del vector, evitando copias innecesarias.
* insert(posicion, valor): Inserta un elemento en una posición específica usando un iterador (ej. v.begin() + 2). [1, 2, 3, 4]

## Eliminación (Quitar elementos)

* pop_back(): Elimina el último elemento del vector de forma rápida. No devuelve el elemento eliminado.
* erase(posicion): Elimina el elemento de una posición específica mediante un iterador. Mueve los elementos restantes.
* clear(): Elimina por completo todos los elementos del vector, dejándolo con un tamaño de 0. [5, 6, 7, 8, 9]

## Búsqueda (Encontrar elementos)
El contenedor std::vector no tiene métodos de búsqueda internos, por lo que se utilizan las funciones de la librería #include <algorithm> junto con los iteradores del vector (begin() y end()): [10]

* std::find(inicio, fin, valor): Busca un valor secuencialmente de izquierda a derecha. Devuelve un iterador al elemento si lo encuentra.
* std::find_if(inicio, fin, condicion): Busca el primer elemento que cumpla con una condición o función lambda personalizada.
* std::binary_search(inicio, fin, valor): Busca un valor de forma ultra rápida, pero requiere que el vector esté ordenado previamente con std::sort. Devuelve un booleano (true/false). [11]

std::vector<int> numeros = {42, 7, 89, 15, 23};

    // Ordenar todo el vector de menor a mayor
    std::sort(numeros.begin(), numeros.end());

    // Resultado: 7, 15, 23, 42, 89
    for (int n : numeros) std::cout << n << " ";


std::vector<Alumno> alumnos = {
        {"Carlos", 7.5},
        {"Ana", 9.8},
        {"Bruno", 8.4},
        {"Diana", 9.8}
    };

    // 1. ORDENAR POR CALIFICACIÓN (De mayor a menor)
    std::sort(alumnos.begin(), alumnos.end(), [](const Alumno& a, const Alumno& b) {
        return a.calificacion > b.calificacion; // '>' para orden descendente
    });
    std::cout << "Alumnos ordenados por mejor nota:\n";

Si necesitas que los registros con valores idénticos conserven estrictamente el orden en que fueron ingresados, C++ te ofrece std::stable_sort.

*/


//const long long MOD = static_cast<long long>(std::pow(10, 9)) + 7;
const long long MOD = 1000000009; // 10^9 + 7

struct tparticipant{
  double rating;
  double probability;
};

int main(){
    int n,k;
    cin>>n>>k;
    vector<tparticipant> participants(n);
    vector<tparticipant> winners;

    for(int i=0;i<n;i++)
      cin>>participants[i].rating;

    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        participants[i].probability = p /1000;
    }

    sort(participants.begin(), participants.end(), [](const tparticipant& a, const tparticipant& b) {
        return a.rating > b.rating;
    });



  return 0;
}
