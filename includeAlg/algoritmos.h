
//
// Created by aldo-bagliano on 16/09/24.
//
#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>
#include <functional>

// Definición de la estructura TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Definición de la clase BinarySearchTree
class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree();  // Constructor
    void insert(int val);  // Insertar un valor en el árbol
    void printInOrder(TreeNode* node);  // Imprimir el árbol en orden
    void printTree();  // Función para imprimir el árbol completo

private:
    TreeNode* insertRec(TreeNode* node, int val);  // Función recursiva para insertar un valor
};

// Declaraciones de los algoritmos de ordenamiento
void bubbleSort(std::vector<int>& arr);
void mergeSort(std::vector<int>& arr);
void SelectionSort(std::vector<int>& datos);

// Declaraciones para medir tiempos
long long medirTiempo(std::function<void(std::vector<int>&)> metodo, std::vector<int>& datos);
long long medirTiempoBST(const std::vector<int>& datos);

#endif // ALGORITMOS_H
