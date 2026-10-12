#pragma once

template <typename T>
class Node {
public:
    explicit Node(T* value)
        : data(value), next(nullptr) {}

    T* data;
    Node<T>* next;
};