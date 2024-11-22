![image](https://github.com/user-attachments/assets/9dc1b9d4-e1ed-4186-bcc2-cb3ed48611d9)

# Proyecto: Minecraft Chest Sorting
EL videojuego "Minecraft" es un juego estilo sandbox que permite a los jugadores construir y crear lo que quieran, al ser tipo sandbox la cantidad de objetos que pueden almacenar en su inventario es illimitada, por lo que un porblema recurrente entre los jugadores es tener el inventario o cofres desordenados, este código busca simular una posible solución a ese problema.

## Descripción del avance 1
En este avance se ha iniciado por un sistema que pregunte la cantidad de bloques que tiene el jugador en su "Hotbar" la cuál puede almacenar hasta 9 tipos de objetos diferentes, cada tipo de bloque se puede almacenar en si mismo hasta 64 veces antes de  tener que utilizar un segundo espacio después el algoritmo ordena dichos bloques en cuanto a la cantidad, aún no se ha implementado la posibilidad de ordenar acorde a el tipo de bloque, así como no se ha añadido el inventario completo del jugador que tiene un total de 36 espacios sin contar armadura ni segunda mano.

En esta versión del programa unicamente recibe valores int y los ordena en un rango de 1 a 64 por meedio de vectores y el sistema de ordenamiento "Merge"

## Descripción del avance 2
En este segundo avance el único cambio importante es que el uso de listas ligadas simples, las funciones se adapataron para leer esta lista y almacenar los valores en un vector y mantener el funcionamiento de forma normal.

### Cambios sobre el primer avance
1. Cambio 1: se cambio el medio de almacenamiento de los datos ingresados de un vector a una lista ligada simple con el objetivo de cumplir con los requerimientos de la segunda entrega.

## Descripción del avance 3
En esta versión del programa se encuentran un gran cantidad de cambios, para conocerlos a detalle revisen el siguiente rubro "Cambios sobre el segundo avance".
El programa ya puede leer y escribir arcchivos lo que ha permito poder tene un sistema de identificación de los objetos por lo que el sistema no solo entrega numeros ordenados, ahora el usuario puede decir que objetos son basados en un catalogo que se encuentra en un archivo de texto "catalogo.txt" así mismo para mayor comodidad la salida del programa se hace en un archivo de texto llamado "salida.txt".

### Cambios sobre el segundo avance
1. Cambio 1: El archivo "Sort.h" fue eliminado e integrado a "list.h" con el objetivo de facilitar el acceso a la información a las listas ligadas y permitir el uso del sistema de ordenamiento "Merge" de froma sencilla y correcta.
2. Cambio 2: El sistema de listas fue cambiado de listas ligadas simples a listas ligadas cilcicas ya que le información que se entrega a "Merge" cambió y con listas ligadas ciclicas se puede trabajar de forma más efectica ya que no hay apuntadores NULL.
3. Cambio 3: "Merge" cambió en cuanto a la información que recibe y ordena, ahora recibe un vector de apuntadores de la lista ligada cíclica y lo ordena dicho vector de apuntadores, con ayuda de la función "sorting()" en el archio "list.h" (linea 210) la lista ligada cíclica reordena sus apuntadores de acuerdo al vector de salida de "Merge" finalmente devolviendo una lista ligada cíclica ordenada de menor a mayor.
4. Cambio 4: Se ha profundizado en lo que el sistema puede llevar a cabo ahora teniendo acceso a un catálogo "catalogo.txt" y en el maín permitiendo elegir las opciones de ese catálogo.
5. Cambio 5: Los nodos de la lista ligada ciclica ahora no solo contienen la cantidad de un obeto si no un identificador que pemite saber el nombre del objeto con ayuda del archivo "catalogo" y la función "getNodeInfo()" en el archivo "list.h" (linea 62).
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
Se ha elegido utilizar el método de ordenamiento "Merge" el cuál se mantiene constante en todo momento al tener un tiempo de compegidad de Θ(n log(n)) en su caso promedio y su peor caso y en su mejor caso Ω(n log(n)) también cuenta con una complejidad de espacio de O(n), al tener en cuenta estos atributos "Merge" destaca rápidamente principalmente porque el sistema si tendrá un límite de objetos que deberá ordenar, en este caso 9, por lo que en la ejecución del programa no se notará de forma relevante ninguno de los 3 casos y se tomará principal ventaja de su complejidad de espacio al cuál es justa.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
El programa utiliza un sistema de estructura de datos de lista ligada cíclica, se toma la ventaja que en ningún momento los nodos de la lista tienen un apuntador NULL, lo que permite que el programa no se estanque a la hora de re ordenar la lista con ayuda del "Merge" ya que recordemos se ordenan primero los apuntadores en un vector y con ayuda de ese mismo los apuntadores de la lista. Así mimso la lista ligada cíclica nos ofrece una constancia de O(n) en todos sus casos e incluso en sus insertions que son los que más utiliza, permitiendo que el programa se mantenga eficaz.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
En análisis de complejidad de todas sus funciones se encuentran como comentarios dentro del código. La complejidad final del programa es: 

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Algoritmo dde ordenamiendo: Merge Sort
Class Sort()
CopyArray: Esta función recibe 2 listas y lo que permite es que el vector A sea identico a la vector B

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.
