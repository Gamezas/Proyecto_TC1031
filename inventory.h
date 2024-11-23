/*  inventory.h
 *  
 *  Nombre: Alejandro Adrián García Martínez
 *  Matrícula: A01707109
 *  Fecha: 11//22/2024
 *  Descripción: Clase para el main del proyecto TC1031, aquí se 
 *  almacenan los valores del "inventario" del usuario los cuales
 *  serán organizados por un algoritmo de ordenamiento en la
 *  clase Sort
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
        List<T> hotbar;

    public:
        Inventory(List<T> &lista);
        Inventory(Inventory& other);

        void setHotbar(List<T> &other);
        List<T> getHotbar();

        std::string printHB();
};

//O(1)
template <class T>
Inventory<T>::Inventory(List<T> &lista)
{
    hotbar = lista;
}

//O(1)
template <class T>
Inventory<T>::Inventory(Inventory<T> &other)
{
    hotbar = other.getHotbar();
}

//O(1)
template <class T>
List<T> Inventory<T>::getHotbar()
{
    return hotbar;
}

//O(1)
template <class T>
void Inventory<T>::setHotbar(List<T> &other)
{
    hotbar = other;
}

//O(n) en todos sus casos se tardará n cantidad de veces dependiendo el tamaño de la lista
template <class T>
std::string Inventory<T>::printHB()
{
    //O(1)
    std::stringstream aux;
    Nodo<T>* aqui = hotbar.getHead();
    aux << aqui->getNodeInfo(aqui);
    aqui = aqui -> siguiente;
    
    //O(n) n es la canridad de valores en la lista
    while(aqui != hotbar.getHead())
    {
        aux << aqui->getNodeInfo(aqui);
        aqui = aqui ->siguiente;
    }

    //O(1)
    return aux.str();
}

#endif
