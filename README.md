![image](https://github.com/user-attachments/assets/9dc1b9d4-e1ed-4186-bcc2-cb3ed48611d9)

# Proyecto: Minecraft Chest Sorting
EL videojuego "Minecraft" es un juego estilo sandbox que permite a los jugadores construir y crear lo que quieran, al ser tipo sandbox la cantidad de objetos que pueden almacenar en su inventario es illimitada, por lo que un problema recurrente entre los jugadores es tener el inventario o cofres desordenados, este código busca simular una posible solución a ese problema.

## Descripción del avance 1
En este avance se ha iniciado por un sistema que pregunte la cantidad de bloques que tiene el jugador en su "Hotbar" la cuál puede almacenar hasta 9 tipos de objetos diferentes, cada tipo de bloque se puede almacenar en si mismo hasta 64 veces antes de tener que utilizar un segundo espacio, después el algoritmo ordena dichos bloques en cuanto a la cantidad. Aún no se ha implementado la posibilidad de ordenar acorde a el tipo de bloque, así como no se ha añadido el inventario completo del jugador que tiene un total de 36 espacios sin contar armadura ni segunda mano.

En esta versión del programa unicamente recibe valores int y los ordena en un rango de 1 a 64 por meedio de vectores y el sistema de ordenamiento "Merge"

## Descripción del avance 2
En este segundo avance el único cambio importante es que el uso de listas ligadas simples, las funciones se adapataron para leer esta lista y almacenar los valores en un vector y mantener el funcionamiento de forma normal.

### Cambios sobre el primer avance
1. Cambio 1: Se cambio el medio de almacenamiento de los datos ingresados de un vector a una lista ligada simple con el objetivo de cumplir con los requerimientos de la segunda entrega.

## Descripción del avance 3
En esta versión del programa se encuentran un gran cantidad de cambios, para conocerlos a detalle revisen el siguiente rubro "Cambios sobre el segundo avance".
El programa ya puede leer y escribir archivos lo que ha permitió poder tener un sistema de identificación de los objetos por lo que el sistema no solo entrega numeros ordenados, ahora el usuario puede decir que objetos son basados en un catalogo que se encuentra en un archivo de texto "catalogo.txt" así mismo para mayor comodidad la salida del programa se hace en un archivo de texto llamado "salida.txt".

### Cambios sobre el segundo avance
1. Cambio 1: El archivo "Sort.h" fue eliminado e integrado a "list.h" con el objetivo de facilitar el acceso a la información a las listas ligadas y permitir el uso del sistema de ordenamiento "Merge" de forma sencilla y correcta.
2. Cambio 2: El sistema de listas fue cambiado de listas ligadas simples a listas ligadas cilcicas ya que le información que se entrega a "Merge" cambió y con listas ligadas ciclicas se puede trabajar de forma más efectiva ya que no hay apuntadores NULL.
3. Cambio 3: "Merge" cambió en cuanto a la información que recibe y ordena, ahora recibe un vector de apuntadores de la lista ligada cíclica y lo ordena dicho vector de apuntadores, con ayuda de la función "sorting()" en el archio "list.h" (linea 210) la lista ligada cíclica reordena sus apuntadores de acuerdo al vector de salida de "Merge" finalmente devolviendo una lista ligada cíclica ordenada de menor a mayor.
4. Cambio 4: Se ha profundizado en lo que el sistema puede llevar a cabo ahora teniendo acceso a un catálogo "catalogo.txt" y en el maín permitiendo elegir las opciones de ese catálogo.
5. Cambio 5: Los nodos de la lista ligada ciclica ahora no solo contienen la cantidad de un objeto si no un identificador que pemite saber el nombre del objeto con ayuda del archivo "catalogo" y la función "getNodeInfo()" en el archivo "list.h" (linea 62).
6. Cambio 6: Ahora hay escritura y lectura de archivos, la lectura se lleva a cabo al leer el archivo de "catálogo".txt" y ahora la salida de información no es por consola si no un archivo de texto llamado "salida.txt".

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ -std=c++11 main.cpp` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./a`

Si se ejecuta en CMD:

`a.exe`

## Descripción de las entradas del avance de proyecto
En cuanto entradas todas son dadas por el usuario y deben ser `int` bajo el rango indicado en el rubro, se implementaron medidas de seguridad para prevenir errores en caso de que el usuario ingrese cosas no válidas esto es con la finalidad de mantener una interacción con el usuario.

## Descripción de las salidas del avance de proyecto
En esta versión la salida del programa es un archivo de texto llamado "salida.txt" donde se encuentra la información ingresada por el usuario de forma ordenada de menor a mayor.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Se ha elegido utilizar el método de ordenamiento "Merge" el cuál se mantiene constante en todo momento al tener un tiempo de compegidad de Θ(n log(n)) en su caso promedio y su peor caso y en su mejor caso Ω(n log(n)) también cuenta con una complejidad de espacio de O(n), al tener en cuenta estos atributos "Merge" destaca rápidamente, principalmente porque el sistema si tendrá un límite de objetos que deberá ordenar, en este caso 9, por lo que en la ejecución del programa no se notará de forma relevante ninguno de los 3 casos y se tomará principal ventaja de su complejidad de espacio al cuál es justa (O(n)) para el tipo de programa que es.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
El programa utiliza un sistema de estructura de datos de lista ligada cíclica, se toma la ventaja que en ningún momento los nodos de la lista tienen un apuntador NULL, lo que permite que el programa no se estanque a la hora de re ordenar la lista con ayuda del "Merge" ya que recordemos se ordenan primero los apuntadores en un vector y con ayuda de ese mismo los apuntadores de la lista. Así mimso la lista ligada cíclica nos ofrece una constancia de O(n) en todos sus casos e incluso en sus insertions es O(1) que son los que más utilizan, permitiendo que el programa se mantenga eficaz en cuanto a la estructura de datos.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
En análisis de complejidad de todas sus funciones se encuentran como comentarios dentro del código. La complejidad final del programa es: 

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Algoritmo dde ordenamiendo: Merge Sort
Class Sort()
MergeSort() (linea 202 list.h) En esta función el programa recibe un vector de apuntadores a nodos de una lista ligada ciclica, la funcón crea dos vectores nuevos, una copia del vector dado y otra que solo es inicializada al tamaño del vactor copia y la función MergeSplit es llamada dando un valor 0 como valor mínimo y el tamaño del vector - 1 como indicador máximo.

MergeSplit() (linea 189 list.h) En esta función se crea un if que funge como caso base, ya que esta función esta diseñada como una función recursiva, su objetivo es llamarse multiples veces y en cada ocación ir dividiendo el vector en 2 hasta quedar únicamente dos valores, estos valores son enviados a la función mergeArray() para ser ordenados una vez ordenados esos valores terminan la ejecución recursiva y se vuelven a mandar a ordenar junto otros dos valores ordenados de la misma manera, así sucesivamente hasta que el vector vuelve a ser uno solo pero esta vez con los valores ordenados de menor a mayor.

MergeArray() (linea 157 list.h) En esta función se reciben dos vectores (A y B) y 3 valores int (low, mid y high), esta función se hace uso de 3 ciclos while que ordenaran y revisarán que los vectores esten ordenados correctamente así mismo se crean 3 instancias i (i_izquierda, i_derecha e i_ordenado) que permitirán conocer que posición del vector estamos ordenando.
Primer while (i_izquierda <= mid && i_derecha <= high)
En este while se busca recorrer el vector mientras que el valor de i_izquierda sea menor o igual que mid y que i_derecha sea menor o igual que el valor high, dentro de este mismo while hay una confición if y else, donde buscamos ajustar el orden de los apuntadores en los vectores con ayuda de la instacia i_ordenado.

Si las condiciones del primer while no se cumplen existen otros dos while while(i_izquierda <= mid) y while(i_derecha <= high) que fungen de forma similar al primer while únicamente haciendo el ordenamiento en el lado izquierdo o derecho respectivamente.

Una vez se comcluya cualquiera de estos 3 ciclos se llama a la función copyArray()

CopyArray() (linea 147 list.h) esta función sencillamente copia todos los cambios hechos en el vector B al vector A, recordemos que en la primera función se crearon dos vectores un con los datos del vector original (A) y otro vacío con el mismo tamaño que el A (B), todos los cambios han ocurrido en el vector B y esta función esos cambios se ven reflejados en el vector A, ya que será el vector A el que se va a regresar una vez termine el merge sort

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
La estructura de datos utilizada en este programa es una lista ligada ciclica.

class List (linea 15 list.h)
En esta clase se sostienen dos apuntadores de la clase Nodo que sirven para conocer la cabeza de la lista y su final, también se declara la función insertion() y sorting() que son las más importnates de la clase

class Nodo (linea 31 list.h)
En esta clase se define los nodos de la lista ligada ciclica todos sus valores son públicos para evitar complicaciones con el acceso a los datos entre clases,
se almacenan 3 datos importantes, la cantidad númerica del nodo, un tag o identificador y un apuntador al siguiente nodo, si es el último nodo este apuntador va hacia la cabeza.

En cuanto a funciones únicamente tiene funciones para acceder a sus datos la importante es la función getNodeInfo(Nodo*<T> nodo) (linea 63) con la cual podemos conocer todo sobre un nodo en específico, aquí se realiza la lectura de archivo del catalogo y regresa que objeto es y que cantidad hay por medio de una linea de string.

Sorting() (linea 212 list.h) esta función de la clase Lista, crea un vector de apuntadores a Nodos que replica la lista cilcica, este vector es enviado a la clase MergSort para su ordenamiento, posteriormente la misma funcion sorting reordena la lista cilcica y deja de utilizar el vector reasignando la cabeza y la cola.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Los mecanismos que se utilizan para consultar la información son principalmente getters implementados en las clases y más especificamente utilizados en los Nodos de la lista ciclica, así mismo se puede acceder a la información precisa, es decir conocer que objeto es exactamente por medio de un tag, con una complejidad de O(n) ya que la función getNodeInfo(Nodo*<T> nodo) (linea 63) se recorre el archivo de texto n veces hasta encontrar el tag indicado, si no se encuentra se indica por medio de un string que el dato no se encontró.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
La lectura de archivos se realiza completamente en la función getNodeInfo(Nodo*<T> nodo) (linea 63), esto se logra gracias a la librería "fstream", en esta función se lee linea por linea por medio de un while, que cierra una vez ya no hayan más lineas en el archivo de texto o se encuentre lo indicado, se utiliza un isstreamstring para poder manipular la linea y que el sistema diferencie entre un valor int y un string, se guarda el valor int en una variable llamada ID y es comparada con el tag que tiene el nodo, si es la misma el programa adquiere el string de la misma linea y lo regresa junto con la cantidad almacenada en el Nodo, si no es el mismo ID continua a la siguiente linea y repite el proceso ya que esta función se realiza n cantidad de veces se puede afirmar que es O(n) en su peor caso y en su caso promedio y en su mejor caso O(1).

#### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta
La escritura de archivos se realiza al finalizar el código (linea 288 main.cpp) donde se crea un archivo de texto nuevo en el espacio de la memoria llamado "salida.txt" en este archivo se guarda toda la información obtenida por la función printHB() (linea 62 inventory.h), función en la cuál adquiere toda la información de cada nodo en orden después de haber sido ordenados y regresa un string con saltos de linea que van directamente a el archivo de texto.
