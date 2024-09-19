# Tarea2_D2 : Análisis de Algoritmos

## Uso

Este programa mide el tiempo de ejecución de varios algoritmos de ordenamiento y estructuras de datos, y genera gráficos para visualizar estos tiempos de ejecucion de cada uno .

### 1. Compilación

Para compilar el programa, usa el siguiente comando:

```bash
g++ -std=c++11 -o main main.cpp -lgtk-3 -lcairo

```

## Ejecucion :

se ejecuta este comando para correr el programa 
```bash
./main
```
Cuando ejecutes el programa, se abrirán ventanas gráficas que mostrarán los gráficos de tiempos de ejecución para cada algoritmo.

Nota: se le tiene que dar al icono de la X en la ventana para poder ir viendo las demás graficas 


## Cambiar el tamaño de n 

Nota: si solo se inserta un valor de n no se va a graficar por tener muy pocos datos 

```bash
std::vector<size_t> tamaños = {10,100,1000}; // se puede agregar más tamaños como {10, 20, 30, 40}
```
## Interpretación de graficas 
```bash

Línea Verde: Tiempo de ejecución en el Mejor Caso.
Línea Azul: Tiempo de ejecución en el Caso Promedio.
Línea Roja: Tiempo de ejecución en el Peor Caso.
```
