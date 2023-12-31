#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/

int findMax(int arr[], int size){
  if(size == 0){
    return -1;
  }

  int elementoMayor=arr[0];
  for(int i=0; i<size ;i++){
    if(arr[i]>elementoMayor){
      elementoMayor=arr[i];
    }
  }

  return elementoMayor;  
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size){
  for (int i = 0; i < size/2 ; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize){
  int contadorPar=0;

  for(int i=0 ; i<size ; i++){
    if(arr[i]%2==0){
      contadorPar++;
    }
  }

  int *arregloPar=(int *)malloc(contadorPar *sizeof(int));
  if(arregloPar==NULL){
    *newSize=0;
    return NULL;
  }

  int indiceArregloPar=0;
  for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            arregloPar[indiceArregloPar] = arr[i];
            indiceArregloPar++;
        }
    }

    *newSize = contadorPar;
    return arregloPar;
  
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,int result[]){
  int i,j,k;
    
  for (i = 0,j = 0,k = 0; i < size1 && j < size2; k++) {
      if (arr1[i] < arr2[j]) {
          result[k] = arr1[i];
          i++;
      } else {
          result[k] = arr2[j];
          j++;
        }
  }
    
  for (; i < size1; i++, k++) {
      result[k] = arr1[i];
  }
    
    for (; j < size2; j++, k++) {
        result[k] = arr2[j];
    }
}


/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size){
  if (size <= 1) {
        return 1;
    }

  int ascendente = 1;
  int descendente = 1;

    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[i - 1]){
            descendente = 0;
        } else if (arr[i] < arr[i - 1]) {
            ascendente = 0;
        }
    }

    if (ascendente) {
        return 1;
    } else if (descendente) {
        return -1;
    } else {
        return 0;
    }
}
  
/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,int anioNacimiento, int anioPublicacion){
  strncpy(libro->titulo, titulo, sizeof(libro->titulo) - 1);
  strncpy(libro->autor.nombre, nombreAutor, sizeof(libro->autor.nombre) - 1);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion; 
}
  

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size){
  if (size == 0){
        return NULL;
  }

  Nodo* primerNodo = (Nodo*)malloc(sizeof(Nodo));
  if (primerNodo == NULL) {
    printf("Error al asignar memoria.\n");
    exit(1);
  }

  primerNodo->numero = arr[0];
  primerNodo->siguiente = NULL;

  Nodo* nodoActual = primerNodo;

  for (int i = 1; i < size; i++) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
      printf("Error al asignar memoria.\n");
      exit(1);
    }

    nuevoNodo->numero = arr[i];
    nuevoNodo->siguiente = NULL;

    nodoActual->siguiente = nuevoNodo;
    nodoActual = nuevoNodo;
  }

  return primerNodo;
  return NULL;
}
  
