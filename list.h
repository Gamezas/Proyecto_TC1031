#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <sstream>

template <class T> class Nodo;

template <class T>
class List
{
    private:
        Nodo<T> *head;
        Nodo<T> *tail;
        int size;

    public:
        List();
        ~List();
        void insertion(T);

        bool empty() const;
        Nodo<T>* getHead() const;
};

template <class T>
class Nodo
{
    private:
        T dato;
        Nodo<T> *siguiente;
        friend class List<T>;
    public:
        T getDato() const;
        Nodo<T>* getNext() const;
};

template <class T>
T Nodo<T>::getDato() const
{
    return dato;
}

template <class T>
Nodo<T>* Nodo<T>::getNext() const
{
    return siguiente;
}


template <class T>
bool List<T>::empty() const
{
    if (size == 0 && head ==  NULL) {
        return true;
    }
    return false;
}

template <class T>
List<T>::List()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
List<T>::~List()
{
    head = NULL;
    size = 0;
}

template <class T>
void List<T>::insertion(T valor)
{
    Nodo<T> *nuevo_nodo = new Nodo<T>;
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = NULL;

    if (empty())
    {
        head = nuevo_nodo;
        tail = nuevo_nodo;
    }

    else
    {
        tail->siguiente = nuevo_nodo;
        tail = nuevo_nodo;
    }
    size++;

}

template <class T>
Nodo<T>* List<T>::getHead() const
{
    return head;
}

#endif