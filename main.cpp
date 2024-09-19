/*  main.cpp
 *  
 *  Nombre: Alejandro Adrián García Martínez
 *  Matrícula: A01707109
 *  Fecha: 20/septiembre/2024
 *  Descripción: Aquí se lleva acabo el código principalmente
 *  se llama a los archivos "sort.h" e "inventario.h" para poder 
 *  llevar acabo el ordenamiento de los datos dados por el usuario
 * 
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "sort.h"
#include "inventory.h"

using namespace std;

template <class T>
string arrayToString(const vector<T> &v) {
	stringstream aux;

	aux << "[" << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << ", " << v[i];
	}
	aux << "]";
	return aux.str();
}


int main()
{
    cout << "Bienvenido a Minecraft Cheft Sorting" << endl <<
    "Porfavor ingresa el numero de la opción que más te interese" << endl <<
    "1. Modo de prueba \n2. Introducir un inventario\n3. Salir" << endl;
    int caso;
    cin >> caso;
    Sort<int> sort;

    switch(caso)
    {
        case 1:
        {
            Inventory inventario;
            vector <int> ordenado = sort.mergeSort(inventario.getHotbar());
            cout << arrayToString(ordenado);

            break;
        }

        case 2:
        {
            vector<int> playerhb(9);
            int slot;
            cout << "Ingresa el primer valor de tu hotbar" << endl <<
            "Recuera que los valores de los bloques van de 0 hasta 64" << endl;
            cin >> slot;

            while(slot < 0 || slot > 64)
            {
                cout << "El valor no esta en el rango, recuerda de 0 a 64" <<
                endl << "Vuelve a intentarlo" << endl;
                cin >> slot;
            }
        
            for(int i = 1; i < 9; i++)
            {
                cout << "Ingresa el valor del slot " << (i+1) << endl;
                cin >> slot;

                while(slot < 0 || slot > 64)
                {
                    cout << "El valor no esta en el rango, recuerda de 0 a 64" <<
                    endl << "Vuelve a intentarlo" << endl;
                    cin >> slot;
                }

                playerhb[i] = slot;

            }
            
            Inventory inventario(playerhb);
            vector <int> ordenado = sort.mergeSort(inventario.getHotbar());
            cout << arrayToString(ordenado);
            break;
        }

        case 3:
        {
            cout << "Que tenga un excelente día :))" << endl;
            break;
        }
    }
    return 0;
}