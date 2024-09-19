//
// Created by aldo-bagliano on 16/09/24.
//
#include "algoritmos.h"
#include <vector>
// Implementación de SelectionSort
void SelectionSort(std::vector<int>& datos) {
    std::size_t n = datos.size();  // Usa std::size_t para evitar conflictos
    for (std::size_t i = 0; i < n - 1; ++i) {
        std::size_t min_idx = i;
        for (std::size_t j = i + 1; j < n; ++j) {
            if (datos[j] < datos[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(datos[i], datos[min_idx]);
    }
}
