#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <sstream>
#include <vector>

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

template <class T>
int Nodo<T>::getCant()
{
    return cant;
}

template <class T>
int Nodo<T>::getTag()
{
    cout << "Entrega\n";
    return tag;
}

template <class T>
Nodo<T>* Nodo<T>::getNext()
{
    return siguiente;
}

template <class T>
std::string Nodo<T>::getNodeInfo(Nodo<T>* nodo)
{
    std::stringstream aux;
    aux << "item: ";
    if(nodo == NULL) cout << "NULL";
    T itemTag = nodo ->tag;
    switch(itemTag)
    {
        case 11:
            aux << "Espada ";
            break;
        case 12:
            aux << "Pico ";
            break;
        case 13:
            aux << "Hacha ";
            break;
        case 14:
            aux << "pala ";
            break;
        case 15:
            aux << "Hazada ";
            break;
        case 21:
            aux << "Pan ";
            break;
        case 22:
            aux << "Manzana ";
            break;
        case 23:
            aux << "Zanahoria ";
            break;
        case 24:
            aux << "Papa ";
            break;
        case 25:
            aux << "Pescado ";
            break;
        case 31:
            aux << "Perla de Ender ";
            break;
        case 32:
            aux << "Huevo ";
            break;
        case 33:
            aux << "Bola de nieve ";
            break;
        case 34:
            aux << "Cartel ";
            break;
        case 41:
            aux << "Pasto ";
            break;
        case 42:
            aux << "Tierra ";
            break;
        case 43:
            aux << "Guijarro ";
            break;
        case 44:
            aux << "Piedra ";
            break;
        case 45:
            aux << "Madrea ";
            break;
        case 46:
            aux << "Tablones de madera ";
            break;
        case 51:
            aux << "Palo ";
            break;
        case 52:
            aux << "Carbon ";
            break;
        case 53:
            aux << "Hierro ";
            break;
        case 54:
            aux << "Oro ";
            break;
        case 55:
            aux << "Redstone ";
            break;
        case 56:
            aux << "Diamante ";
            break;
    }
    aux << "Cantidad: " << nodo -> cant << "\n";
    return aux.str();
}

template <class T>
List<T>::List()
{
    head = NULL;
    tail = NULL;
}

template <class T>
bool List<T>::empty()
{
    return (head == NULL);
}

template <class T>
Nodo<T>* List<T>::getHead() const
{
    return head;
}

template <class T>
void List<T>::insertion(T valor, T id)
{
    Nodo<T> *nuevo_nodo = new Nodo<T>;
    nuevo_nodo->cant = valor;
    nuevo_nodo->tag = id;
    nuevo_nodo->siguiente = NULL;

    if (empty())
    {
        head = nuevo_nodo;
        tail = nuevo_nodo;
    }

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

	while (i_izquierda <= mid && i_derecha <= high){
		if (A[i_izquierda] -> cant < A[i_derecha] -> cant){
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
		mergeSplit(A, B, low, mid);
		mergeSplit(A, B, mid + 1, high);
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

template <class T>
void List<T>::sorting()
{
    Nodo<T>* cabeza = head;
    std::vector<Nodo<T>*> salida;
    while(cabeza -> siguiente != head)
    {
        salida.push_back(cabeza);
        cabeza = cabeza ->siguiente;
    }
    salida.push_back(cabeza);
    cabeza = nullptr;
    Sort<Nodo<T>*> sort;
    salida = sort.mergeSort(salida);
    head = salida[0];
    cabeza = head;

    for(int i = 1; i <= salida.size() - 1; i++)
    {
        cabeza->siguiente = salida[i];
        cabeza = cabeza ->siguiente;
    }
    tail = cabeza;
    tail ->siguiente = head;
    cout << "a";
}
#endif