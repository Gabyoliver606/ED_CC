#pragma once

#include <iostream>

struct Node {
    int data;
    Node *next;

    Node(int data = 0, Node *next = nullptr) : data(data), next(next) {
    }
};

struct List {
    Node *head {nullptr};
    int tamanho {};

    List() {}

    ~List() {
        destroy(head);
    }

    bool empty() {
        return head == nullptr;
    }
    
    void destroy(Node * node) {
        if(empty()) {
            return;
        }
        
        destroy(node->next);
        
        delete(node);
    }

    void push_back(int value) {
        if (empty()) {
            this->head = new Node(value);
            return;
        }

        auto node = this->head;

        while (node->next != nullptr) {
            node = node->next;
        }

        node->next = new Node(value);

        tamanho += 1;
    }

    void push_front(int value) {
        auto node = new Node(value);

        node->next = this->head;
        this->head = node; 
        
        tamanho += 1;
    }

    Node * __pop_back(Node * node) {
        if (node->next == nullptr) {
            delete node;

            return nullptr;
        }
        
        node->next = __pop_back(node->next);

        return node;
    }

    void pop_back() {
        head = __pop_back(head);
    }

    void pop_front() {
        if (empty()) {
            return;
        }

        auto node = head;

        head = head->next;

        delete node;

        tamanho -= 1;
    }

    int size() {
        return this->tamanho;
    }

    friend std::ostream& operator<<(std::ostream& os, List &lista) {
        os << "[ ";
        
        auto node = lista.head;

        while(node != nullptr) {
            os << node->data << " ";
            
            node = node->next;
        }

        os << "]" << std::endl;

        return os;
    }
};