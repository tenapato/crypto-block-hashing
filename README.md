# Crypto Block Mining Simulation

##### Integrantes:
1. Rodrigo Benavente García - A01026973
2. Patricio Tena Zozaya - A01027293


---
## 1. Aspectos generales

### 1.1 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz de todo el proyecto
    - README.md			# Archivo con los datos del proyecto (este archivo)
    - source			# Carpeta con el código fuente de la solución
        - main.c        # Solución en secuencial
        - main2.c       # Solución en paralelo en una sola maquina
        - main3.c.      # Solucion en paralelo en varios nodos
    - docs			    # Carpeta con la documentación del proyecto: PDF, imágenes, etc.
```

## 2. Descripción del problema

El problema que se resuelve es la implementación del hasheado de una cripto moneda en paralelo. Para esto se utilizo la función de hasheo SHA-256 y una implementación en fuerza bruta para un n número de datos. 

## 3. Solución

A continuación aparecen descritos los diferentes elementos que forman parte de la solución del proyecto.

### 3.1 Análisis de concurrencia
 
Uno de los problemas que encontramos es que cada máquina analizaba los mismos datos, para resover esto cada nodo tenían que dividirse una cierta cantidad de datos y analizar solo ese rango, para asi encontralos de una manera mucho más eficientes.

Otro problema era que al un nodo encontar el hash deseado, tenía que mandar una señal a las demás máquinas para que detuvieran su búsqueda. Para eso utilizamos una variable compartida, que se accesaba dentro de la zona crítica, y asi todos los nodos supieran si es hash ya se había, o no, encontrado. Este problema fue resuelto al utilizar un broadcast que le informara a los nodos e hilos que ya se encontró el hash deseado, para que estos dejen de seuir buscando el hash
### 3.2 Análisis de los inhibidores del paralelismo

Un inhibidor que encontramos es que cuando un hilo dentro de un nodo encontraba el hash deseado le tenía que enviar la variable a los otros hilos y nodos para que estos se detuvieran una vez que el hash fuera encontrado.

### 3.3 Arquitectura de la solución

![img_1](docs/diagrama1.jpeg)
## 4. Pasos a seguir para utilizar el proyecto

### 4.1 Dependencias y requisitos

- OpenMP
#### 4.1.1 Frameworks
No aplica
#### 4.1.2 Librerías de funciones o dependencias
- OpenMP
- Vagrant
- VirtualBox
- Crypt
#### 4.1.3 Guía de uso

1. Instalar [VirtualBox](https://www.virtualbox.org/)
2. Instalar [Vagrant](https://www.vagrantup.com/)
3. Crea una carpeta nombrada mpi-vagrant en tu computadora
4. Descarga a la carpeta mpi-vagrant los archivos [Vagrantfile](docs/Vagrantfile) y [Machines](docs/machines)
5. Abre una Terminal en tu computadora y cámbiate a la carpeta mpi-vagrant
6. Clona el repositorio: 

        git clone https://github.com/tenapato/crypto-block-hashing
7. Inicia el clúster: 
        
        vagrant up
8. Una vez que termine el comando anterior, accede por SSH al nodo 1 con el comando:
        
        vagrant ssh node1
    - Desde el nodo 1, verifica que tienes conectividad al nodo 2 con el comando: ssh node2. La primera vez te preguntará si aceptas que se adicione la llave al archivo de autorización, selecciona que si (Y) y continua.
    - Regresa al nodo 1 con el comando: exit
    - Desde el nodo 1, verifica que tienes conectividad al nodo 3 con el comando: ssh node3. La primera vez te preguntará si aceptas que se adicione la llave al archivo de autorización, selecciona que si (Y) y continua.
    - Regresa al nodo 1 con el comando: exit
9. Una vez dentro del nodo 1:
    - Moverte a la ubicacion del codigo:

            cd /vagrant/crypto-block-hashing/

    - Compilar el código:

            mpicc main3.c -lcrypt -fopenmp
    - Correrlo:

            mpirun -np 3 -f /vagrant/machines ./a.out 'd'
        >Donde d es un int de la dificultad del hasheado
10. Para apagar vagrant:

        vagrant halt
    

## 5. Referencias

- https://www.freecodecamp.org/news/how-bitcoin-mining-really-works-38563ec38c87/
- https://www.youtube.com/watch?v=bBC-nXj3Ng4&t=1s
- https://bitcoin.org/bitcoin.pdf
