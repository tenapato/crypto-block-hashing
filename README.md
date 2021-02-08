# *[Poner aquí el Título del Proyecto]*
---
#### Materia: *TC2025-Programación Avanzada*

##### Integrantes:
1. *[Poner aquí Nombre y Apellidos del integrante 1]* - *[Poner aquí su Matrícula]* 
2. *[Poner aquí Nombre y Apellidos del integrante 2]* - *[Poner aquí su Matrícula]* 
3. *[Poner aquí Nombre y Apellidos del integrante 3]* - *[Poner aquí su Matrícula]* 
4. *[Poner aquí Nombre y Apellidos del integrante 4]* - *[Poner aquí su Matrícula]* 

---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte del proyecto, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.

### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos del proyecto, favor de tenerlos presente para que cumpla con todos.

* Toda la programación debe realizarse en C.
* La solución al problema debe utilizar el máximo nivel de paralelismo posible, utilizando PThreads u OpenMP y MPI.
* La solución debe ejecutarse en un clúster formado como mínimo por el mismo número de nodos que integrantes tenga el equipo.
* Se debe realizar un análisis de los problemas de concurrencia que se pueden presentar y resolverse de la manera correcta, evitando en todo momento las esperas activas.
* Para resolver los problemas de concurrencia se deben utilizar algunas de las técnicas estudiadas en el semestre.
* Todo el código y la documentación del proyecto debe alojarse en este repositorio de GitHub. Favor de mantener la estructura de carpetas propuesta.
* El código debe estar documentado siguiendo los estándares definidos para el lenguaje de programación C.

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz de todo el proyecto
    - README.md			# Archivo con los datos del proyecto (este archivo)
    - source			# Carpeta con el código fuente de la solución
    - docs			    # Carpeta con la documentación del proyecto: PDF, imágenes, etc.
```

### 1.3 Documentación  del proyecto

Como parte de la entrega final del proyecto, se debe incluir la siguiente información:

* Descripción del problema a resolver.
* Análisis exhaustivo de los problemas de concurrencia que se presentan y una explicación clara de cómo se resuelve cada uno de ellos en la solución propuesta.
* Análisis exhauistivo de los inhibidores del paralelismo presentes en el problema planteado y una explicación clara de cómo se resuelve cada uno de ellos en la solución implementada.
* Diagrama con la arquitectura de la solución que incluya: nodos del clúster, componentes de código que se ejecuta en cada nodo, si se hace un *scatter*, *gather*, indicar quien es el nodo maestro y cuáles son los nodos obreros, etc.
* Descripción de cada uno de los componentes de la solución.
* Guía de configuración, compilación y ejecución de la solución implementada y todos los componentes, liberías, etc. que se requieran.

## 2. Descripción del problema

*[Incluya aquí la descripción del problema a resolver.]*

## 3. Solución

A continuación aparecen descritos los diferentes elementos que forman parte de la solución del proyecto.

### 3.1 Análisis de concurrencia

*[Incluya aquí un análisis exhaustivo de los problemas de concurrencia que se presentan y una explicación clara de cómo se resuelve cada uno de ellos en la solución propuesta.]*

### 3.2 Análisis de los inhibidores del paralelismo

*[Incluya aquí un análisis exhaustivo de los inhibidores del paralelismo presentes en el problema planteado y una explicación clara de cómo se resuelve cada uno de ellos en la solución implementada.]*

### 3.3 Arquitectura de la solución

*[Incluya aquí un diagrama donde se aprecie la arquitectura de la solución propuesta, así como la interacción entre los diferentes componentes de la misma.]*

*[Incluya una explicación del flujo de la información entre los diferentes componentes.]*

### 3.4 Descripción de los componentes

*[Incluya aquí una descripción detallada de cada uno de los componentes de la solución.]*

## 4. Pasos a seguir para utilizar el proyecto

### 4.1 Dependencias y requisitos

*[Incluya aquí una explicación de los diferentes frameworks y librerías utilizadas.]*

#### 4.1.1 Frameworks

#### 4.1.2 Librerías de funciones o dependencias

#### 4.1.3 Guía de uso

*[Incluya aquí una guía paso a paso para poder utilizar el proyecto, desde la clonación de este repositorio, la compilación, instalación de dependencias hasta la ejecución de la solución en el clúster.]*

## 5. Referencias

*[Incluya aquí las referencias a sitios de interés, artículos, libros, documentos y cualquier otra información que haya utilizado para realizar el proyecto y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
