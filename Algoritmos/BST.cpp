//
// Created by aldo-bagliano on 16/09/24.
//
#include "algoritmos.h"
#include <iostream>
#include <chrono>

// Constructor del árbol binario de búsqueda
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

// Función para insertar un valor en el árbol
void BinarySearchTree::insert(int val) {
    root = insertRec(root, val);
}

// Función recursiva para insertar un valor en el árbol
TreeNode* BinarySearchTree::insertRec(TreeNode* node, int val) {
    if (node == nullptr) {
        return new TreeNode(val);
    }
    if (val < node->val) {
        node->left = insertRec(node->left, val);
    } else if (val > node->val) {
        node->right = insertRec(node->right, val);
    }
    return node;
}

// Función para imprimir el árbol en orden (in-order traversal)
void BinarySearchTree::printInOrder(TreeNode* node) {
    if (node != nullptr) {
        printInOrder(node->left);
        std::cout << node->val << " ";
        printInOrder(node->right);
    }
}

// Función para imprimir el árbol entero
void BinarySearchTree::printTree() {
    printInOrder(root);
    std::cout << std::endl;
}

// Función para medir el tiempo de inserción en el árbol

long long medirTiempoBST(const std::vector<int>& datos) {
    BinarySearchTree bst;

    auto start = std::chrono::high_resolution_clock::now();

    // Insertar los datos en el árbol
    for (int val : datos) {
        bst.insert(val);
    }

    auto end = std::chrono::high_resolution_clock::now();

    // Calcular duración en nanosegundos
    std::chrono::duration<double, std::nano> duration = end - start;
    return static_cast<long long>(duration.count());
}

