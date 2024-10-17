/*  inventory.h
 *  
 *  Nombre: Alejandro Adrián García Martínez
 *  Matrícula: A01707109
 *  Fecha: 20/septiembre/2024
 *  Descripción: Clase para el main del proyecto TC1031, aquí se 
 *  almacenan los valores del "inventario" del usuario los cuales
 *  serán organizados por un algoritmo de ordenamiento en "sort.h"
 * 
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <iostream>
#include <vector>
#include "list.h"

using namespace std;

template <class T>
class Inventory
{
    private:
        vector<int> hotbar;

    public:
        Inventory();
        Inventory(List<T> &lista);
        Inventory(Inventory& other);

        void setHotbar(vector <int>);
        vector<int> getHotbar();
};

template <class T>
Inventory<T>::Inventory()
{
    vector <int> vect = {1,3,2,4,6,5,9,7,8};
    hotbar = vect;
}

template <class T>
Inventory<T>::Inventory(List<T> &lista) 
{
    vector <int> vect;
    Nodo<T> *aqui = lista.getHead();
   
    while (aqui != nullptr)
    {
        vect.push_back(aqui -> getDato());
        aqui = aqui -> getNext();
    }   


    hotbar = vect;
}

template <class T>
Inventory<T>::Inventory(Inventory& other)
{
    hotbar = other.getHotbar();
}

template <class T>
vector<int> Inventory<T>::getHotbar()
{
    return hotbar;
}

template <class T>
void Inventory<T>::setHotbar(vector <int> vect)
{
    hotbar = vect;
}

#endif
