//
// Created by aldo-bagliano on 16/09/24.
//
#include "AllSortedLinkedList.h"
#include <algorithm>
#include <chrono>
#include <iostream>

// Constructor
SortedLinkedList::SortedLinkedList() : head(nullptr), tail(nullptr) {}

// Destructor
SortedLinkedList::~SortedLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Insertar elemento en la lista ordenada
void SortedLinkedList::insert(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr) {
        // La lista está vacía
        head = tail = newNode;
    } else if (value <= head->data) {
        // Insertar antes del primer elemento
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (value >= tail->data) {
        // Insertar después del último elemento
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    } else {
        // Insertar en el medio
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

// Imprimir la lista
void SortedLinkedList::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Ordenar la lista usando un algoritmo proporcionado
void SortedLinkedList::sort(std::function<void(std::vector<int>&)> algoritmo) {
    std::vector<int> datos;
    Node* current = head;
    while (current != nullptr) {
        datos.push_back(current->data);
        current = current->next;
    }

    algoritmo(datos);

    // Re-construir la lista ordenada
    current = head;
    for (int value : datos) {
        current->data = value;
        current = current->next;
    }
}
