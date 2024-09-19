/*  sort.h
 *  
 *  Nombre: Alejandro Adrián García Martínez
 *  Matrícula: A01707109
 *  Fecha: 20/septiembre/2024
 *  Descripción: Clase para el main del proyecto TC1031, aquí se 
 *  almacenan los valores del "inventario" del usuario los cuales
 *  serán organizados por un algoritmo de ordenamiento en "sort.h"
 * 
 *  Se elegió el método "Merge sort" buscando una velocidad adecuada
 *  en todos los posibles casos, ya que en un futuro la cantidad de
 *  "slots" aumentará hasta 36 variando en objetos y bloques.
 * 
*/

#ifndef SORT_H_
#define SORT_H_

#include <iostream>
#include <vector>
#include "inventory.h"

using namespace std;

template <class T>
class Sort
{
    private:
        void swap(vector <T>&, int, int);
        void copyArray(vector<T>&, vector<T>&, int, int);
	void mergeArray(vector<T>&, vector<T>&, int, int, int);
	void mergeSplit(vector<T>&, vector<T>&, int, int);
    
    public:
        vector<T> mergeSort(const vector<T>&);
};

template <class T>
void Sort<T>::swap(vector <T>&v, int i, int j)
{
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

template <class T>
void Sort<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

template <class T>
void Sort<T>::mergeArray(vector<T>&A, vector<T> &B, int low, int mid, int high)
{
    int i_ordenado = low;
	int i_izquierda = low;
	int i_derecha = mid + 1;

	//Ciclo para ordenar en B, la parte izquierda de A con respectp a la parte derecha de A
	while (i_izquierda <= mid && i_derecha <= high){
		if (A[i_izquierda] < A[i_derecha]){
			B[i_ordenado] = A[i_izquierda];
			i_izquierda++;
		}
		else{
			B[i_ordenado] = A[i_derecha];
			i_derecha++;
		}
		i_ordenado++;
	}

	while(i_izquierda <= mid){
		B[i_ordenado] = A[i_izquierda];
		i_ordenado++;
		i_izquierda++;
	}

	while(i_derecha <= high){
		B[i_ordenado] = A[i_derecha];
		i_ordenado++;
		i_derecha++;
	}

	copyArray(A, B, low, high);
}

template <class T>
void Sort<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high)
{
	if(low < high)
    {
		int mid = (low + high) / 2;
		//Calcular la mitad
		mergeSplit(A, B, low, mid);
		// Calcular la izquierda
		mergeSplit(A, B, mid + 1, high);
		// Calcular la derecha
		mergeArray(A, B, low, mid, high);
	}
	
}

template <class T>
vector<T> Sort<T>::mergeSort(const vector<T> &source)
{
	vector<T> v(source);
	vector<T> tmp(v.size());

	mergeSplit(v, tmp, 0, v.size() - 1);

	return v;
}


#endif
