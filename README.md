![image](https://github.com/user-attachments/assets/9dc1b9d4-e1ed-4186-bcc2-cb3ed48611d9)

# Tercera entrega
Para la tercera entrega no hay actualizacion en read me, se planean hacer de forma corecta junto con el analisis de complejidad para la entrega final.
Esta entrega sin embargo actualiza todo el código por completo y retirando el archivo "sort.h" e integrando sus contenidos a "list.h". El código también
ya tiene un catálogo con tags que permite al identificación de objetos y no solamente números ordenados.

## Como utilizar el código
En esta entrega se hace lectura de archivos, por lo que para pruebas se deben realizar en el archivo "entrada.txt" de la siguiente forma
El primer valor indica si el programa se ejecutará o no, 1. se ejecuta 2. No lo hace
El segundo indica la cantidad de objetos que van a haber en la lista a ordenar este va de 1 a 9 si se introduce un valor no válido se le avisará al usuario,
por lo que si se escribe un caso de prueba para exceder esto se recomiendo hacerlo como "1 10 4 ..."

Los siguientes valores entran en los 5 catálogos diferentes

### Catálogo 1
Todos los valores en este catálogo su cantidad es definida a 1 automáticamente para seguir las reglas del juego, este catálogo hay 5 opciones
1. Espada
2. Pico
3. Hacha
4. Pala
5. Hazada

Para introducir una de estas opciones en el archivo de entrada se recomiend hacerlo de la siguiente forma Ejemplo: "... 1 1 1 2 1 3 1 5 ..."

### Catálogo 2
Todos los valores en este catálogo entran en un rango del 1 al 64 y son seleccionadas con el número 2, en este catálogo hay 5 opciones
1. Pan
2. Manzana
3. Zanahoria
4. Papa
5. Pescado

Para este catálogo al ser stackable (puede haber más de 1 en un mismo slot) hay que colocar la cantidad que habra en el slot, si esta pasa de rango, por
seguridad el código vuelve a preguntar, si se busca realizar una prueba de esto se recomienda hacerlo de la siguiente forma "... 2 1 -1 15 ..."
se recomienda elegirlo en el archivo de entrada de la siguiente forma Ejemplo "... 2 1 64 2 3 12 2 5 3 ..."

### Catálogo 3
Todos los valores en este catálogo entran en un rango del 1 al 16, respetando las reglas del juego y son seleccionadas con el número 3, en este catálogo hay 4 opciones
1. Perlas de Enderman
2. Huevo
3. Bolas de Nieve
4. Carteles

Para este catálogo al ser stackable (puede haber más de 1 en un mismo slot) hay que colocar la cantidad que habra en el slot, si esta pasa de rango, por
seguridad el código vuelve a preguntar, si se busca realizar una prueba de esto se recomienda hacerlo de la siguiente forma "... 3 1 -1 15 ..."
se recomienda elegirlo en el archivo de entrada de la siguiente forma Ejemplo "... 3 1 12 3 3 1 3 4 3 ..."

### Catálogo 4
Todos los valores en este catálogo entran en un rango del 1 al 64 y son seleccionadas con el número 4, en este catálogo hay 6 opciones
1. Pasto
2. Tierra
3. Guijarro
4. Piedra
5. Madera
6. Tablones de Madera

Para este catálogo al ser stackable (puede haber más de 1 en un mismo slot) hay que colocar la cantidad que habra en el slot, si esta pasa de rango, por
seguridad el código vuelve a preguntar, si se busca realizar una prueba de esto se recomienda hacerlo de la siguiente forma "... 4 1 -1 15 ..."
se recomienda elegirlo en el archivo de entrada de la siguiente forma Ejemplo "... 4 1 64 4 3 12 4 5 3 ..."

### catálogo 5
Todos los valores en este catálogo entran en un rango del 1 al 64 y son seleccionadas con el número 5, en este catálogo hay 6 opciones
1. Palos
2. Carbón
3. Hierro
4. Oro
5. Restone
6. Diamantes

Para este catálogo al ser stackable (puede haber más de 1 en un mismo slot) hay que colocar la cantidad que habra en el slot, si esta pasa de rango, por
seguridad el código vuelve a preguntar, si se busca realizar una prueba de esto se recomienda hacerlo de la siguiente forma "... 5 1 -1 15 ..."
se recomienda elegirlo en el archivo de entrada de la siguiente forma Ejemplo "... 5 1 64 5 3 12 5 5 3 ..."

## Salidas
Todas las salidas del programa serán registradas en el arhcivo de texto "salida.txt" y se encontraran ordenados de menor a mayor en cuanto a cantidad, dando prioridad a los objetos del catálogo 1.

Así mismo se compila el archivo de la siguiente forma:

`g++ -std=c++11 main.cpp` 

Y Ejecuta de la siguiente forma:

`a.exe` ó `a`

Se menciona nuevamente que todas las selecciones tienen medidas de seguridad en caso que se coloque un número fuera de rango, por lo que si se busca probar estas medidas de seguridad, se recomienda siempre colocar depue´s un valor dentro del rango o que sea en el catálogo Ejemplo: "... 5 1 -1 15 ..." ó "... 8 1 1 2 ..."

# Proyecto: Minecraft Chest Sorting
Minecraft Chest Sorting busca resolver uno de los problemas que más seguido se encuentran los jugadores
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
