/*  main.cpp
 *  
 *  Nombre: Alejandro Adrián García Martínez
 *  Matrícula: A01707109
 *  Fecha: 11//22/2024
 *  Descripción: Aquí se lleva acabo el código principalmente
 *  se llama a los archivos "sort.h" e "inventario.h" para poder 
 *  llevar acabo el ordenamiento de los datos dados por el usuario
 * 
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "inventory.h"
#include "list.h"

using namespace std;

//O (n log n) en todos sus casos debido al switch
int main()
{
    //O(1)
    std::cout << "Bienvenido a Minecraft Cest Sorting, elige una opcion\n" << "1. Introducir inventario\n" 
    << "2. Salir\n";
    int choice1;
    std::cin >> choice1;

    //O (n log n) debido al caso 1
    switch (choice1)
    {
        //O (n log n) debido a la función de sorting que es esta misma complejidad
        case 1:
        {
            //O(1)
            List<int> playerhb;
            int loop;
            std::cout << "Cuantos objetos hay en tu hotbar? Elije del 1 al 9\n";
            std::cin >> loop;

            //Mejor caso O(1)
            //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
            //Peor caso O(n)
            while(loop < 1 || loop > 9)
            {
                std::cout << "El valor ingresado es fuera del rango de 1 a 9, vuelve a intentarlo\n";
                std::cin >> loop;
            }

            //O(1)
            int item = 0;
            int itemTag = 0;
            int itemCant = 0;

            
            while(loop > 0)
            {
                //O(1)
                item, itemTag, itemCant = 0;
                std::cout << "Que objeto planeas almacenar?\n" << "1. Herramienta\n" << "2. Alimento\n"
                << "3. Items especiales\n" << "4. Bloques\n" << "5. Items comunes\n";
                std::cin >> item;

                //Mejor caso O(1)
                //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                //Peor caso O(n)
                while(item < 1 || item > 5)
                {
                    std::cout << "No seleccionaste una opción valida vuelve a intentar";
                    std::cout << "Que objeto planeas almacenar?\n" << "1. Herramienta\n" << "2. Alimento\n"
                    << "3. Items especiales\n" << "4. Bloques\n" << "5. Items comunes\n";
                    std::cin >> item;
                }


                switch(item)
                {
                    //Mejor caso O(1)
                    //Caso promedio: O(n) n es la cantidad de valores inválidos que da usuario antes de 1 válido
                    //Peor caso: O(n)
                    case 1:

                        //O(1)
                        std::cout << "Que herramienta vas a almacenar?\n" << "1. Espada\n" << "2. Pico\n"
                        << "3. Hacha\n" << "4. Pala\n" << "5. Hazada\n";
                        std::cin >> itemTag;

                        //Mejor caso O(1)
                        //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                        //Peor caso O(n)
                        while(itemTag < 1 || itemTag > 5)
                        {
                            std::cout << "No seleccionaste una opción valida vuelve a intentar\n";
                            std::cout << "Que herramienta vas a almacenar?\n" << "1. Espada\n" << "2. Pico\n"
                            << "3. Hacha\n" << "4. Pala\n" << "5. Hazada\n";
                            std::cin >> itemTag;
                        }

                        //O(1)
                        switch(itemTag)
                        {
                            //O(1)
                            case 1:
                                playerhb.insertion(1,11);
                                break;
                            //O(1)
                            case 2:
                                playerhb.insertion(1,12);
                                break;
                            //O(1)
                            case 3:
                                playerhb.insertion(1,13);
                                break;
                            //O(1)
                            case 4:
                                playerhb.insertion(1,14);
                                break;
                            //O(1)
                            case 5:
                                playerhb.insertion(1,15);
                                break;
                        }
                        //O(1)
                        loop--;
                        break;

                    //Mejor caso O(1)
                    //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                    //Peor caso O(n)
                    case 2:

                        //O(1)
                        std::cout << "Que alimento vas a almacenar?\n" << "1. Pan\n" << "2. Manzana\n"
                        << "3. Zanahoria\n" << "4. Papa\n" << "5. Pescado\n";
                        std::cin >> itemTag;

                        //Mejor caso O(1)
                        //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                        //Peor caso O(n)
                        while(itemTag < 1 || itemTag > 5)
                        {
                            std::cout << "No seleccionaste una opción valida vuelve a intentar";
                            std::cout << "Que alimento vas a almacenar?\n" << "1. Pan\n" << "2. Manzana\n"
                            << "3. Zanahoria\n" << "4. Papa\n" << "5. Pescado\n";
                            std::cin >> itemTag;
                        }

                        //O(1)
                        std::cout << "Este objeto se puede almacenar de 1 hasta 64 veces, cuanto vas a almacenar?\n";
                        std::cin >> itemCant;

                        //Mejor caso O(1)
                        //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                        //Peor caso O(n)
                        while(itemCant < 1 || itemCant > 64)
                        {
                            std::cout << "El valor esta fuera del rango de 1 a 64, vuelve a intentar\n";
                            std::cin >> itemCant;
                        }

                        //O(1)
                        switch(itemTag)
                        {
                            //O(1)
                            case 1:
                                playerhb.insertion(itemCant,21);
                                break;
                            //O(1)
                            case 2:
                                playerhb.insertion(itemCant,22);
                                break;
                            //O(1)
                            case 3:
                                playerhb.insertion(itemCant,23);
                                break;
                            //O(1)
                            case 4:
                                playerhb.insertion(itemCant,24);
                                break;
                            //O(1)
                            case 5:
                                playerhb.insertion(itemCant,25);
                                break;
                        }
                        //O(1)
                        loop--;
                        break;

                    
                    //Mejor caso O(1)
                    //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                    //Peor caso O(n)
                    case 3:
                        //O(1)
                        //Estos items son especiales ya que solo se pueden almacenar x16 por slot
                        std::cout << "Que item especial vas a almacenar?\n" << "1. Perla de Ender\n" 
                        << "2. Huevos\n" << "3. Bola de Nieve\n" << "4. Carteles\n";
                        std::cin >> itemTag;

                        //Mejor caso O(1)
                        //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                        //Peor caso O(n)
                        while(itemTag < 1 || itemTag > 5)
                        {
                            std::cout << "No seleccionaste una opción valida vuelve a intentar";
                            std::cout << "Que item especial vas a almacenar?\n" << "1. Perla de Ender\n" 
                            << "2. Huevos\n" << "3. Bola de Nieve\n" << "4. Carteles\n";
                            std::cin >> itemTag;
                        }

                        //O(1)
                        std::cout << "Este objeto se puede almacenar de 1 hasta 16 veces, cuanto vas a almacenar?\n";
                        std::cin >> itemCant;

                        //Mejor caso O(1)
                        //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                        //Peor caso O(n)
                        while(itemCant < 1 || itemCant > 16)
                        {
                            std::cout << "El valor esta fuera del rango de 1 a 16, vuelve a intentar\n";
                            std::cin >> itemCant;
                        }

                        //O(1)
                        switch(itemTag)
                        {
                            //O(1)
                            case 1:
                                playerhb.insertion(itemCant,31);
                                break;
                            //O(1)
                            case 2:
                                playerhb.insertion(itemCant,32);
                                break;
                            //O(1)
                            case 3:
                                playerhb.insertion(itemCant,33);
                                break;
                            //O(1)
                            case 4:
                                playerhb.insertion(itemCant,34);
                                break;
                        }
                        //O(1)
                        loop--;
                        break;
                    
                    //Mejor caso O(1)
                    //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                    //Peor caso O(n)
                    case 4:
                        //O(1)
                        std::cout << "Que tipo de bloque buscas almacenar?\n" << "1. Pasto\n" << "2. Tierra\n"
                        << "3. Guijarro\n" << "4. Piedra\n" << "5. Madera\n" << "6. Tablones de Madera\n";
                        std::cin >> itemTag;

                        //Mejor caso O(1)
                        //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                        //Peor caso O(n)
                        while(itemTag < 1 || itemTag > 6)
                        {
                            std::cout << "No seleccionaste una opción valida vuelve a intentar";
                            std::cout << "Que tipo de bloque buscas almacenar?\n" << "1. Pasto\n" << "2. Tierra\n"
                            << "3. Guijarro\n" << "4. Piedra\n" << "5. Madera\n" << "6. Tablones de Madera\n";
                            std::cin >> itemTag;
                        }

                        //O(1)
                        std::cout << "Este objeto se puede almacenar de 1 hasta 64 veces, cuanto vas a almacenar?\n";
                        std::cin >> itemCant;

                        //Mejor caso O(1)
                        //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                        //Peor caso O(n)
                        while(itemCant < 1 || itemCant > 64)
                        {
                            std::cout << "El valor esta fuera del rango de 1 a 64, vuelve a intentar\n";
                            std::cin >> itemCant;
                        }

                        //O(1)
                        switch(itemTag)
                        {
                            //O(1)
                            case 1:
                                playerhb.insertion(itemCant,41);
                                break;
                            //O(1)
                            case 2:
                                playerhb.insertion(itemCant,42);
                                break;
                            //O(1)
                            case 3:
                                playerhb.insertion(itemCant,43);
                                break;
                            //O(1)
                            case 4:
                                playerhb.insertion(itemCant,44);
                                break;
                            //O(1)
                            case 5:
                                playerhb.insertion(itemCant,45);
                                break;
                            //O(1)
                            case 6:
                            playerhb.insertion(itemCant,46);
                            break;
                        }
                        //O(1)
                        loop--;
                        break;

                    //Mejor caso O(1)
                    //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                    //Peor caso O(n)
                    case 5:
                        //O(1)
                        std::cout << "Que item normal buscas almacenar?\n" << "1. Palos\n" << "2. Carbon\n"
                        << "3. Hierro\n" << "4. Oro\n" << "5. Redstone\n" << "6. Diamantes\n";
                        std::cin >> itemTag; 

                        //Mejor caso O(1)
                        //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                        //Peor caso O(n)
                        while(itemTag < 1 || itemTag > 6)
                        {
                            std::cout << "No seleccionaste una opción valida vuelve a intentar";
                            std::cout << "Que item normal buscas almacenar?\n" << "1. Palos\n" << "2. Carbon\n"
                            << "3. Hierro\n" << "4. Oro\n" << "5. Redstone\n" << "6. Diamantes\n";
                            std::cin >> itemTag;
                        }

                        //O(1)
                        std::cout << "Este objeto se puede almacenar de 1 hasta 64 veces, cuanto vas a almacenar?\n";
                        std::cin >> itemCant;

                        //Mejor caso O(1)
                        //Caso promedio O(n) n es la cantidad de valores no válidos entregados al sistema
                        //Peor caso O(n)
                        while(itemCant < 1 || itemCant > 64)
                        {
                            std::cout << "El valor esta fuera del rango de 1 a 64, vuelve a intentar\n";
                            std::cin >> itemCant;
                        }

                        //O(1)
                        switch(itemTag)
                        {
                            //O(1)
                            case 1:
                                playerhb.insertion(itemCant,51);
                                break;
                            //O(1)
                            case 2:
                                playerhb.insertion(itemCant,52);
                                break;
                            //O(1)
                            case 3:
                                playerhb.insertion(itemCant,53);
                                break;
                            //O(1)
                            case 4:
                                playerhb.insertion(itemCant,54);
                                break;
                            //O(1)
                            case 5:
                                playerhb.insertion(itemCant,55);
                                break;
                            //O(1)
                            case 6:
                            playerhb.insertion(itemCant,56);
                            break;
                        }
                        //O(1)
                        loop--;
                        break;
                }
            }

            //O (n log n)
            playerhb.sorting();

            //O(1)
            std::cout << "Tu invetario se encuentra en el archivo \"Salida.txt\" \n\n";
            Inventory<int> inventario(playerhb);

            //O(n)
            std::string salida = inventario.printHB();

            //O(1)
            ofstream SalidaS("salida.txt");

            //O(1)
            // Verificar si el archivo se abrió correctamente
            if (!SalidaS) {
            cerr << "No se pudo abrir el archivo para escritura." << endl;
            return 1;
            }
            
            //O(1)
            SalidaS << salida;

            SalidaS.close();
        }
        //O(1)
        case 2:
            //O(1)
            std::cout << "Excelente dia";
            break;
    }
    return 0;
}
