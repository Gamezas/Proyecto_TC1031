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
#include <fstream>
#include "inventory.h"
#include "list.h"

using namespace std;


int main()
{
    //Leer read me para poder utilizar los arhivos de forma correcta :)
    ifstream entrada("entrada.txt");

    // Verificar si el archivo se abrió correctamente
    if (!entrada) {
        cerr << "No se pudo abrir el archivo para lectura." << endl;
        return 1;
    }

    //O(1)
    std::cout << "Bienvenido a Minecraft Cest Sorting, elige una opcion\n" << "1. introducir inventario\n" 
    << "2. Salir\n";
    int choice1;
    entrada >> choice1;


    switch (choice1)
    {
        case 1:
        {
            //O(1)
            List<int> playerhb;
            int loop;
            std::cout << "Cuantos objetos hay en tu hotbar? Elije del 1 al 9\n";
            entrada >> loop;

            //O(n)
            while(loop < 1 || loop > 9)
            {
                std::cout << "El valor ingresado es fuera del rango de 1 a 9, vuelve a intentarlo\n";
                entrada >> loop;
            }

            //O(1)
            int item = 0;
            int itemTag = 0;
            int itemCant = 0;

            
            while(loop > 0)
            {
                item, itemTag, itemCant = 0;
                std::cout << "Que objeto planeas almacenar?\n" << "1. Herramienta\n" << "2. Alimento\n"
                << "3. Items especiales\n" << "4. Bloques\n" << "5. Items comunes\n";
                entrada >> item;

                while(item < 1 || item > 5)
                {
                    std::cout << "No seleccionaste una opción valida vuelve a intentar";
                    std::cout << "Que objeto planeas almacenar?\n" << "1. Herramienta\n" << "2. Alimento\n"
                    << "3. Items especiales\n" << "4. Bloques\n" << "5. Items comunes\n";
                    entrada >> item;
                }

                switch(item)
                {
                    case 1:
                        std::cout << "Que herramienta vas a almacenar?\n" << "1. Espada\n" << "2. Pico\n"
                        << "3. Hacha\n" << "4. Pala\n" << "5. Hazada\n";
                        entrada >> itemTag;

                        while(itemTag < 1 || itemTag > 5)
                        {
                            std::cout << "No seleccionaste una opción valida vuelve a intentar";
                            std::cout << "Que herramienta vas a almacenar?\n" << "1. Espada\n" << "2. Pico\n"
                            << "3. Hacha\n" << "4. Pala\n" << "5. Hazada\n";
                            entrada >> itemTag;
                        }

                        switch(itemTag)
                        {
                            case 1:
                                playerhb.insertion(1,11);
                                break;
                            case 2:
                                playerhb.insertion(1,12);
                                break;
                            case 3:
                                playerhb.insertion(1,13);
                                break;
                            case 4:
                                playerhb.insertion(1,14);
                                break;
                            case 5:
                                playerhb.insertion(1,15);
                                break;
                        }
                        loop--;
                        break;

                    case 2:
                        std::cout << "Que alimento vas a almacenar?\n" << "1. Pan\n" << "2. Manzana\n"
                        << "3. Zanahoria\n" << "4. Papa\n" << "5. Pescado\n";
                        entrada >> itemTag;

                        while(itemTag < 1 || itemTag > 5)
                        {
                            std::cout << "No seleccionaste una opción valida vuelve a intentar";
                            std::cout << "Que alimento vas a almacenar?\n" << "1. Pan\n" << "2. Manzana\n"
                            << "3. Zanahoria\n" << "4. Papa\n" << "5. Pescado\n";
                            entrada >> itemTag;
                        }

                        std::cout << "Este objeto se puede almacenar de 1 hasta 64 veces, cuanto vas a almacenar?";
                        entrada >> itemCant;

                        while(itemCant < 1 || itemCant > 64)
                        {
                            std::cout << "El valor esta fuera del rango de 1 a 64, vuelve a intentar";
                            entrada >> itemCant;
                        }

                        switch(itemTag)
                        {
                            case 1:
                                playerhb.insertion(itemCant,21);
                                break;
                            case 2:
                                playerhb.insertion(itemCant,22);
                                break;
                            case 3:
                                playerhb.insertion(itemCant,23);
                                break;
                            case 4:
                                playerhb.insertion(itemCant,24);
                                break;
                            case 5:
                                playerhb.insertion(itemCant,25);
                                break;
                        }
                        loop--;
                        break;

                    case 3:
                        //Estos items son especiales ya que solo se pueden almacenar x16 por slot
                        std::cout << "Que item especial vas a almacenar?\n" << "1. Perla de Ender\n" 
                        << "2. Huevos\n" << "3. Bola de Nieve\n" << "4. Carteles\n";
                        entrada >> itemTag;

                        while(itemTag < 1 || itemTag > 5)
                        {
                            std::cout << "No seleccionaste una opción valida vuelve a intentar";
                            std::cout << "Que item especial vas a almacenar?\n" << "1. Perla de Ender\n" 
                            << "2. Huevos\n" << "3. Bola de Nieve\n" << "4. Carteles\n";
                            entrada >> itemTag;
                        }

                        std::cout << "Este objeto se puede almacenar de 1 hasta 16 veces, cuanto vas a almacenar?";
                        entrada >> itemCant;

                        while(itemCant < 1 || itemCant > 16)
                        {
                            std::cout << "El valor esta fuera del rango de 1 a 16, vuelve a intentar";
                            entrada >> itemCant;
                        }

                        switch(itemTag)
                        {
                            case 1:
                                playerhb.insertion(itemCant,31);
                                break;
                            case 2:
                                playerhb.insertion(itemCant,32);
                                break;
                            case 3:
                                playerhb.insertion(itemCant,33);
                                break;
                            case 4:
                                playerhb.insertion(itemCant,34);
                                break;
                        }
                        loop--;
                        break;
                    
                    case 4:
                        std::cout << "Que tipo de bloque buscas almacenar?\n" << "1. Pasto\n" << "2. Tierra\n"
                        << "3. Guijarro\n" << "4. Piedra\n" << "5. Madera\n" << "6. Tablones de Madera\n";
                        entrada >> itemTag;

                        while(itemTag < 1 || itemTag > 6)
                        {
                            std::cout << "No seleccionaste una opción valida vuelve a intentar";
                            std::cout << "Que tipo de bloque buscas almacenar?\n" << "1. Pasto\n" << "2. Tierra\n"
                            << "3. Guijarro\n" << "4. Piedra\n" << "5. Madera\n" << "6. Tablones de Madera\n";
                            entrada >> itemTag;
                        }

                        std::cout << "Este objeto se puede almacenar de 1 hasta 64 veces, cuanto vas a almacenar?";
                        entrada >> itemCant;

                        while(itemCant < 1 || itemCant > 64)
                        {
                            std::cout << "El valor esta fuera del rango de 1 a 64, vuelve a intentar";
                            entrada >> itemCant;
                        }

                        switch(itemTag)
                        {
                            case 1:
                                playerhb.insertion(itemCant,41);
                                break;
                            case 2:
                                playerhb.insertion(itemCant,42);
                                break;
                            case 3:
                                playerhb.insertion(itemCant,43);
                                break;
                            case 4:
                                playerhb.insertion(itemCant,44);
                                break;
                            case 5:
                                playerhb.insertion(itemCant,45);
                                break;
                            case 6:
                            playerhb.insertion(itemCant,46);
                            break;
                        }
                        loop--;
                        break;

                    case 5:
                        std::cout << "Que item normal buscas almacenar?\n" << "1. Palos\n" << "2. Carbon\n"
                        << "3. Hierro\n" << "4. Oro\n" << "5. Redstone\n" << "6. Diamantes\n";
                        entrada >> itemTag; 

                        while(itemTag < 1 || itemTag > 6)
                        {
                            std::cout << "No seleccionaste una opción valida vuelve a intentar";
                            std::cout << "Que item normal buscas almacenar?\n" << "1. Palos\n" << "2. Carbon\n"
                            << "3. Hierro\n" << "4. Oro\n" << "5. Redstone\n" << "6. Diamantes\n";
                            entrada >> itemTag;
                        }

                        std::cout << "Este objeto se puede almacenar de 1 hasta 64 veces, cuanto vas a almacenar?";
                        entrada >> itemCant;

                        while(itemCant < 1 || itemCant > 64)
                        {
                            std::cout << "El valor esta fuera del rango de 1 a 64, vuelve a intentar";
                            entrada >> itemCant;
                        }

                        switch(itemTag)
                        {
                            case 1:
                                playerhb.insertion(itemCant,51);
                                break;
                            case 2:
                                playerhb.insertion(itemCant,52);
                                break;
                            case 3:
                                playerhb.insertion(itemCant,53);
                                break;
                            case 4:
                                playerhb.insertion(itemCant,54);
                                break;
                            case 5:
                                playerhb.insertion(itemCant,55);
                                break;
                            case 6:
                            playerhb.insertion(itemCant,56);
                            break;
                        }
                        loop--;
                        break;
                }
            }

            playerhb.sorting();
            std::cout << "Aqui esta tu inventario\n\n";
            Inventory<int> inventario(playerhb);

            std::string salida = inventario.printHB();

            ofstream SalidaS("salida.txt");

            // Verificar si el archivo se abrió correctamente
            if (!SalidaS) {
            cerr << "No se pudo abrir el archivo para escritura." << endl;
            return 1;
            }
            
            SalidaS << salida;

            SalidaS.close();
        }
        case 2:
            std::cout << "Excelente dia";

            entrada.close();
            break;
    }
    return 0;
}
