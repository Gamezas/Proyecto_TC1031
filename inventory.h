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
        List<T> hotbar;

    public:
        Inventory(List<T> &lista);
        Inventory(Inventory& other);

        void setHotbar(List<T> &other);
        List<T> getHotbar();

        std::string printHB();
};

template <class T>
Inventory<T>::Inventory(List<T> &lista)
{
    hotbar = lista;
}

template <class T>
Inventory<T>::Inventory(Inventory<T> &other)
{
    hotbar = other.getHotbar();
}

template <class T>
List<T> Inventory<T>::getHotbar()
{
    return hotbar;
}

template <class T>
void Inventory<T>::setHotbar(List<T> &other)
{
    hotbar = other;
}

template <class T>
std::string Inventory<T>::printHB()
{
    std::stringstream aux;
    Nodo<T>* aqui = hotbar.getHead();
    aux << aqui->getNodeInfo(aqui);
    aqui = aqui -> siguiente;
    if(aqui == hotbar.getHead()) cout << "Crash\n";
    while(aqui != hotbar.getHead())
    {
        aux << aqui->getNodeInfo(aqui);
        aqui = aqui ->siguiente;
    }
    return aux.str();
}

#endif