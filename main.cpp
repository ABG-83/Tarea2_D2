//
// Created by aldo-bagliano on 16/09/24.
#include <chrono>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstdlib>  // Para rand() y srand()
#include <numeric>
#include "algoritmos.h"
#include "Graficas/graficas.h"

// Función para medir el tiempo de ejecución en nanosegundos
long long medirTiempo(std::function<void(std::vector<int>&)> metodo, std::vector<int>& datos) {
    auto start = std::chrono::high_resolution_clock::now();
    metodo(datos);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

void generarDatosMejorCaso(std::vector<int>& datos) {
    std::iota(datos.begin(), datos.end(), 0);
}

void generarDatosCasoPromedio(std::vector<int>& datos) {
    std::generate(datos.begin(), datos.end(), []() { return rand() % 1000; });
}

void generarDatosPeorCaso(std::vector<int>& datos) {
    std::iota(datos.begin(), datos.end(), 0);
    std::reverse(datos.begin(), datos.end());
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    std::vector<size_t> tamaños = {10,100,1000,10000}; // se puede cambiar los valor de n aquí

    std::vector<double> tiempos_bubble_mejor, tiempos_bubble_promedio, tiempos_bubble_peor;
    std::vector<double> tiempos_merge_mejor, tiempos_merge_promedio, tiempos_merge_peor;
    std::vector<double> tiempos_bst_mejor, tiempos_bst_promedio, tiempos_bst_peor;
    std::vector<double> tiempos_selection_mejor, tiempos_selection_promedio, tiempos_selection_peor;

    // Medición de tiempos para BubbleSort
    std::cout << "Medición de tiempo para BubbleSort (en nanosegundos):" << std::endl;
    for (size_t tamaño : tamaños) {
        std::vector<int> datos(tamaño);

        // Mejor caso
        generarDatosMejorCaso(datos);
        long long tiempo_mejor = medirTiempo(bubbleSort, datos);

        // Caso promedio
        generarDatosCasoPromedio(datos);
        long long tiempo_promedio = medirTiempo(bubbleSort, datos);

        // Peor caso
        generarDatosPeorCaso(datos);
        long long tiempo_peor = medirTiempo(bubbleSort, datos);

        // Determinar el orden de los casos
        if (tiempo_mejor > tiempo_promedio) std::swap(tiempo_mejor, tiempo_promedio);
        if (tiempo_promedio > tiempo_peor) std::swap(tiempo_promedio, tiempo_peor);
        if (tiempo_mejor > tiempo_promedio) std::swap(tiempo_mejor, tiempo_promedio);

        tiempos_bubble_mejor.push_back(tiempo_mejor);
        tiempos_bubble_promedio.push_back(tiempo_promedio);
        tiempos_bubble_peor.push_back(tiempo_peor);

        std::cout << "BubbleSort mejor caso (n=" << tamaño << "): " << tiempo_mejor << " ns" << std::endl;
        std::cout << "BubbleSort caso promedio (n=" << tamaño << "): " << tiempo_promedio << " ns" << std::endl;
        std::cout << "BubbleSort peor caso (n=" << tamaño << "): " << tiempo_peor << " ns" << std::endl;
    }

    // Medición de tiempos para MergeSort
    std::cout << "Medición de tiempo para MergeSort (en nanosegundos):" << std::endl;
    for (size_t tamaño : tamaños) {
        std::vector<int> datos(tamaño);

        // Mejor caso
        generarDatosMejorCaso(datos);
        long long tiempo_mejor = medirTiempo(mergeSort, datos);

        // Caso promedio
        generarDatosCasoPromedio(datos);
        long long tiempo_promedio = medirTiempo(mergeSort, datos);

        // Peor caso
        generarDatosPeorCaso(datos);
        long long tiempo_peor = medirTiempo(mergeSort, datos);

        // Determinar el orden de los casos
        if (tiempo_mejor > tiempo_promedio) std::swap(tiempo_mejor, tiempo_promedio);
        if (tiempo_promedio > tiempo_peor) std::swap(tiempo_promedio, tiempo_peor);
        if (tiempo_mejor > tiempo_promedio) std::swap(tiempo_mejor, tiempo_promedio);

        tiempos_merge_mejor.push_back(tiempo_mejor);
        tiempos_merge_promedio.push_back(tiempo_promedio);
        tiempos_merge_peor.push_back(tiempo_peor);

        std::cout << "MergeSort mejor caso (n=" << tamaño << "): " << tiempo_mejor << " ns" << std::endl;
        std::cout << "MergeSort caso promedio (n=" << tamaño << "): " << tiempo_promedio << " ns" << std::endl;
        std::cout << "MergeSort peor caso (n=" << tamaño << "): " << tiempo_peor << " ns" << std::endl;
    }

    // Medición de tiempos para Binary Search Tree (BST)
    std::cout << "Medición de tiempo para Binary Search Tree (en nanosegundos):" << std::endl;
    for (size_t tamaño : tamaños) {
        std::vector<int> datos(tamaño);

        // Mejor caso
        generarDatosMejorCaso(datos);
        long long tiempo_mejor = medirTiempoBST(datos);

        // Caso promedio
        generarDatosCasoPromedio(datos);
        long long tiempo_promedio = medirTiempoBST(datos);

        // Peor caso
        generarDatosPeorCaso(datos);
        long long tiempo_peor = medirTiempoBST(datos);

        // Determinar el orden de los casos
        if (tiempo_mejor > tiempo_promedio) std::swap(tiempo_mejor, tiempo_promedio);
        if (tiempo_promedio > tiempo_peor) std::swap(tiempo_promedio, tiempo_peor);
        if (tiempo_mejor > tiempo_promedio) std::swap(tiempo_mejor, tiempo_promedio);

        tiempos_bst_mejor.push_back(tiempo_mejor);
        tiempos_bst_promedio.push_back(tiempo_promedio);
        tiempos_bst_peor.push_back(tiempo_peor);

        std::cout << "BST mejor caso (n=" << tamaño << "): " << tiempo_mejor << " ns" << std::endl;
        std::cout << "BST caso promedio (n=" << tamaño << "): " << tiempo_promedio << " ns" << std::endl;
        std::cout << "BST peor caso (n=" << tamaño << "): " << tiempo_peor << " ns" << std::endl;
    }

    // Medición de tiempos para SelectionSort
    std::cout << "Medición de tiempo para SelectionSort (en nanosegundos):" << std::endl;
    for (size_t tamaño : tamaños) {
        std::vector<int> datos(tamaño);

        // Mejor caso
        generarDatosMejorCaso(datos);
        long long tiempo_mejor = medirTiempo(SelectionSort, datos);

        // Caso promedio
        generarDatosCasoPromedio(datos);
        long long tiempo_promedio = medirTiempo(SelectionSort, datos);

        // Peor caso
        generarDatosPeorCaso(datos);
        long long tiempo_peor = medirTiempo(SelectionSort, datos);

        // Determinar el orden de los casos
        if (tiempo_mejor > tiempo_promedio) std::swap(tiempo_mejor, tiempo_promedio);
        if (tiempo_promedio > tiempo_peor) std::swap(tiempo_promedio, tiempo_peor);
        if (tiempo_mejor > tiempo_promedio) std::swap(tiempo_mejor, tiempo_promedio);

        tiempos_selection_mejor.push_back(tiempo_mejor);
        tiempos_selection_promedio.push_back(tiempo_promedio);
        tiempos_selection_peor.push_back(tiempo_peor);

        std::cout << "SelectionSort mejor caso (n=" << tamaño << "): " << tiempo_mejor << " ns" << std::endl;
        std::cout << "SelectionSort caso promedio (n=" << tamaño << "): " << tiempo_promedio << " ns" << std::endl;
        std::cout << "SelectionSort peor caso (n=" << tamaño << "): " << tiempo_peor << " ns" << std::endl;
    }

    // Generar gráficos por cada algoritmo
    generarGraficoPorAlgoritmo(tiempos_bubble_mejor, tiempos_bubble_promedio, tiempos_bubble_peor, tamaños, "BubbleSort");
    generarGraficoPorAlgoritmo(tiempos_merge_mejor, tiempos_merge_promedio, tiempos_merge_peor, tamaños, "MergeSort");
    generarGraficoPorAlgoritmo(tiempos_bst_mejor, tiempos_bst_promedio, tiempos_bst_peor, tamaños, "BST");
    generarGraficoPorAlgoritmo(tiempos_selection_mejor, tiempos_selection_promedio, tiempos_selection_peor, tamaños, "SelectionSort");

    return 0;
}
