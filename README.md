![image](https://github.com/user-attachments/assets/9dc1b9d4-e1ed-4186-bcc2-cb3ed48611d9)

# Proyecto: Minecraft Chest Sorting
Minecraft Chest Sorting busca rexxolver uno de los problemas que más seguido se encuentran los jugadores
del juego Minecraft, que el inventario y los cofres se encuentran desordenados.

## Descripción del avance 1
En la versión actuual del documento se integra el sistema de listas enlazadas simples, se elige de esta forma ya
que el sistema no necesita saber cuál era la posición anterior, únicamente la cabeza, la cola y el valor siguiente del nodo actual. También se corriguen los errores de la entrega anterior

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ -std=c++11 main.cpp` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`a.exe` ó `a`

## Descripción de las entradas del avance de proyecto
Para el proyecto se necesita un primera entrada para seleccionar una de las opciones del menú.

Eligiendo 1 el sistema ejecutará un caso de prueba.
Eligiendo 2 el sistema ejecutará el programa normal, pidiendo al usuraio 9 entredas de valores input entre el 0 al 64
Eligiendo 3 el sistema concluirá

## Descripción de las salidas del avance de proyecto
Las salidas son las entradas de forma ordenadas del menor al mayor

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El sistema de ordenaiento Merge permite una solución de tipo O(n log(n)) en promedio así como en su peor caso, esto permite que se mantenga una velocidad constante en el sistema y se pueda escalar de 9 valores a 36 que es el obejtivo final.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
El sistema de estructuras de datos de listas simples es el ideal ya que doblemente ligado o circular si bien pueden funcionar en el sistema no se le mucho uso a lo que los diferencia del simple, pues el algoritmo unicamente necesita saber cuál es nodo siguiente y no tiene un uso necesario en el nodo anterior.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
En este sistema se selecciona el sistema de ordenamiento merge ya que permite una solución O(n log(n)) en la mayoría de los casos, esto es útil ya que actualmente se ordena únicamente la hotbar del jugador el cuál contiene 9  espacios y la velocidad no cambia entre el mejor o peor de los casos, sigue siendo rápida. Cuado 
se escale el programa a almacenar 36 espacios merge mantendrá la velocidad a comparación de otros métodos de
ordenamiento.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
El sistema únicamente enecsita conocer el incio y el final de la lista, así como el nodo siguiente del que esta actualmente, no necesita saber el nodo anterior ni cliclar la lista, es por esto que la lista ligada simple es excelente para el sistema.
