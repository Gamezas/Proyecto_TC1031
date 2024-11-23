/*  list.h
 *  
 *  Nombre: Alejandro Adrián García Martínez
 *  Matrícula: A01707109
 *  Fecha: 11/22/2024
 *  Descripción: Este archivo almacena el inventario del usuario
 *  y permite su ordenaminto por medio de las clases List y Sort
 *  respectivamente esto se logra gracias a Mergesort y una lista
 *  ligada ciclica, revisar README para más detalles
 * 
*/

#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;


template <class T> class Nodo;

template <class T>
class List
{
    private:
        Nodo<T>* head;
        Nodo<T>* tail;
    public:
        List();
        void insertion(T valor, T id);

        bool empty();
        Nodo<T>* getHead() const;

        void sorting();
};

template <class T>
class Nodo
{
    public:
        T cant;
        T tag;
        Nodo<T>* siguiente;
        friend class List<T>;
        int getCant();
        int getTag();
        std::string getNodeInfo(Nodo<T>* nodo);
        Nodo<T>* getNext();
};

//O(1)
template <class T>
int Nodo<T>::getCant()
{
    return cant;
}

//O(1)
template <class T>
int Nodo<T>::getTag()
{
    return tag;
}

//O(1)
template <class T>
Nodo<T>* Nodo<T>::getNext()
{
    return siguiente;
}

//Mejor caso O(1)
//Caso promedio O(n) n es la cantidad de lineas que debe revisar hasta llegar a la correcta
//Peor caso O(n)
template <class T>
std::string Nodo<T>::getNodeInfo(Nodo<T>* nodo)
{
    //O(1)
    std::stringstream aux;
    aux << "item: ";

    //O(1)
    ifstream catalogo("catalogo.txt");

    //O(1)
    if(!catalogo)
    {
        return "El archivo de catalogo no fué encontrado";
    }

    //O(1)
    std::string linea;
    int id = 0;
    std::string txt = "";

    //Mejor caso O(1)
    //Caso promedio O(n) n es la cantidad de lineas que debe leer
    //Peor caso O(n)
    while(std::getline(catalogo, linea))
    {
        //O(1)
        std::istringstream stream(linea);
        stream >> id >> txt;
        //O(1)
        if(id == nodo -> getTag())
        {
            aux << txt << ", Cantidad: " << nodo -> cant << "\n";
            return aux.str();
        }
    }

    return "ID no encontrado";
}

//O(1)
template <class T>
List<T>::List()
{
    head = NULL;
    tail = NULL;
}

//O(1)
template <class T>
bool List<T>::empty()
{
    return (head == NULL);
}

//O(1)
template <class T>
Nodo<T>* List<T>::getHead() const
{
    return head;
}


//O(1)
template <class T>
void List<T>::insertion(T valor, T id)
{
    //O(1)
    Nodo<T> *nuevo_nodo = new Nodo<T>;
    nuevo_nodo->cant = valor;
    nuevo_nodo->tag = id;
    nuevo_nodo->siguiente = NULL;

    //O(1)
    if (empty())
    {
        head = nuevo_nodo;
        tail = nuevo_nodo;
    }

    //O(1)
    else
    {
        tail->siguiente = nuevo_nodo;
        nuevo_nodo->siguiente = head;
        tail = nuevo_nodo;
    }
}

template <class T>
class Sort
{
    private:
        void copyArray(vector<T>&, vector<T>&, int, int);
	    void mergeArray(vector<T>&, vector<T>&, int, int, int);
	    void mergeSplit(vector<T>&, vector<T>&, int, int);
    
    public:
        vector<T> mergeSort(const vector<T>&);
};

//Mejor caso O(n) n es la cantidad de iteraciones del bucle
//Caso promedio O(n)
//Peor caso O(n)
template <class T>
void Sort<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high)
{
    //O(1)
    for (int i = low; i <= high; i++)
    {
        //O(1)
        A[i] = B[i];
    }
}

//Mejor caso O(n) n es la cantidad de iteraciones del bucle
//Caso promedio O(n)
//Peor caso O(n)
template <class T>
void Sort<T>::mergeArray(vector<T>&A, vector<T> &B, int low, int mid, int high)
{
    //O(1)
    int i_ordenado = low;
	int i_izquierda = low;
	int i_derecha = mid + 1;

    //Mejor caso O(n) n es la cantidad de iteraciones del bucle
    //Caso promedio O(n)
    //Peor caso O(n)
	while (i_izquierda <= mid && i_derecha <= high){
        //O(1)
		if (A[i_izquierda] -> cant < A[i_derecha] -> cant)
        {
			B[i_ordenado] = A[i_izquierda];
			i_izquierda++;
		}
        //O(1)
		else
        {
			B[i_ordenado] = A[i_derecha];
			i_derecha++;
		}
		i_ordenado++;
	}

    //Mejor caso O(n) n es la cantidad de iteraciones del bucle
    //Caso promedio O(n)
    //Peor caso O(n)
	while(i_izquierda <= mid){
		B[i_ordenado] = A[i_izquierda];
		i_ordenado++;
		i_izquierda++;
	}

    //Mejor caso O(n) n es la cantidad de iteraciones del bucle
    //Caso promedio O(n)
    //Peor caso O(n)
	while(i_derecha <= high){
		B[i_ordenado] = A[i_derecha];
		i_ordenado++;
		i_derecha++;
	}

    //Caso promedio O(n)
	copyArray(A, B, low, high);
}

//O(n log n) el numero de recursiones es log2(n) y es la misma recursion en todos sus casos
template <class T>
void Sort<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high)
{
	if(low < high)
    {
        //O(1)
		int mid = (low + high) / 2;
        //Recursión 1, se hace n cantidad de veces
		mergeSplit(A, B, low, mid);
        //Recursión 2, se hace n cantidad de veces
		mergeSplit(A, B, mid + 1, high);
        //Caso promedio O(n)
		mergeArray(A, B, low, mid, high);
	}
	
}

//O (n log n) Esto es en todos sus casos debido a la complejidad de la función mergeSplit
template <class T>
vector<T> Sort<T>::mergeSort(const vector<T> &source)
{
    //O(n) n es la cantidad e valores a copiar
	vector<T> v(source);
	vector<T> tmp(v.size());

    //O(n log n)
	mergeSplit(v, tmp, 0, v.size() - 1);

	return v;
}

//O (n log n) Esto es en todos sus casos debido a la complejidad de la función mergeSplit
template <class T>
void List<T>::sorting()
{
    //O(1)
    Nodo<T>* cabeza = head;
    std::vector<Nodo<T>*> salida;

    //O(n) n cantidad de valores en la lista hasta tail
    while(cabeza -> siguiente != head)
    {
        salida.push_back(cabeza);
        cabeza = cabeza ->siguiente;
    }
    //O(1)
    salida.push_back(cabeza);
    cabeza = nullptr;

    //O(1)
    Sort<Nodo<T>*> sort;

    //O(n log n)
    salida = sort.mergeSort(salida);

    //O(1)
    head = salida[0];
    cabeza = head;

    //O(n) n es la cantidad de iteraciones de i hasta ser mayor que salida.size()
    for(int i = 1; i <= salida.size() - 1; i++)
    {
        cabeza->siguiente = salida[i];
        cabeza = cabeza ->siguiente;
    }

    //O(1)
    tail = cabeza;
    tail ->siguiente = head;
}

#endif
