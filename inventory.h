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

using namespace std;

class Inventory
{
    private:
        vector<int> hotbar;

    public:
        Inventory();
        Inventory(vector<int>& vector);
        Inventory(Inventory& other);

        void setHotbar(vector <int>);
        vector<int> getHotbar();
};


Inventory::Inventory()
{
    vector <int> vect = {9,3,4,2,5,8,6,7,1};
    hotbar = vect;
}

Inventory::Inventory(vector<int>& vector)
{
    hotbar = vector;
}

Inventory::Inventory(Inventory& other)
{
    hotbar = other.getHotbar();
}

vector<int> Inventory::getHotbar()
{
    return hotbar;
}

void Inventory::setHotbar(vector <int> vect)
{
    hotbar = vect;
}

// Debería añadir un destructor?

#endif