//
// Created by aldo-bagliano on 16/09/24.
//
#include "algoritmos.h"
#include "algoritmos.h"
#include <vector>
#include <algorithm> // Para std::copy

// Función para combinar dos sub-vectores ordenados
void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Crear vectores temporales
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Copiar datos a vectores temporales L[] y R[]
    std::copy(arr.begin() + left, arr.begin() + middle + 1, L.begin());
    std::copy(arr.begin() + middle + 1, arr.begin() + right + 1, R.begin());

    // Combinar los vectores temporales de vuelta en arr[left..right]

    int i = 0; // Índice inicial de la primera sublista
    int j = 0; // Índice inicial de la segunda sublista
    int k = left; // Índice inicial de la lista combinada

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si hay alguno
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay alguno
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Encontrar el punto medio
        int middle = left + (right - left) / 2;

        // Ordenar la primera y segunda mitad
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Combinar las mitades ordenadas
        merge(arr, left, middle, right);
    }
}

// Función  para manejar los índices de la matriz
void mergeSort(std::vector<int>& arr) {
    if (arr.size() > 1) {
        mergeSort(arr, 0, arr.size() - 1);
    }
}
