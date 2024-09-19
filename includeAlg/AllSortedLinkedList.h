//
// Created by aldo-bagliano on 16/09/24.
//
#ifndef ALL_SORTED_LINKED_LIST_H
#define ALL_SORTED_LINKED_LIST_H

#include <vector>
#include <functional>
#include <chrono>

// Declaración de la función medirTiempo
long long medirTiempo(std::function<void(std::vector<int>&)> metodo, std::vector<int>& datos);

// Definición de la clase SortedLinkedList
class SortedLinkedList {
public:
    SortedLinkedList();
    ~SortedLinkedList();

    void insert(int value);
    void print() const;
    void sort(std::function<void(std::vector<int>&)> algoritmo);

private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
};

#endif // ALL_SORTED_LINKED_LIST_H
