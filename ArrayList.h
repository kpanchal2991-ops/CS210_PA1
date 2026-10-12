#pragma once

#include <iostream>
#include "List.h"

template <typename T>
class ArrayList : public List<T> {
public:
    ArrayList()
        : size_(0) {
        for (int i = 0; i < CAPACITY; ++i) {
            data_[i] = nullptr;
        }
    }

    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }

        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }

        data_[0] = value;
        ++size_;
    }

    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }

        delete data_[0];

        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }

        data_[size_ - 1] = nullptr;
        --size_;
    }

    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) {
                return true;
            }
        }

        return false;
    }

    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }

        std::cout << std::endl;
    }

    void addAnywhere(int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "Invalid ArrayList insertion position."
                      << std::endl;
            delete value;
            return;
        }

        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            delete value;
            return;
        }

        for (int i = size_; i > position; --i) {
            data_[i] = data_[i - 1];
        }

        data_[position] = value;
        ++size_;
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "Invalid ArrayList deletion position."
                      << std::endl;
            return;
        }

        delete data_[position];

        for (int i = position; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }

        data_[size_ - 1] = nullptr;
        --size_;
    }

    void reverse() override {
        int left = 0;
        int right = size_ - 1;

        while (left < right) {
            T* temporary = data_[left];
            data_[left] = data_[right];
            data_[right] = temporary;

            ++left;
            --right;
        }
    }

    void concat(List<T>* other) override {
        ArrayList<T>* otherList =
            dynamic_cast<ArrayList<T>*>(other);

        if (otherList == nullptr) {
            std::cout << "ArrayList concat requires another ArrayList."
                      << std::endl;
            return;
        }

        if (size_ + otherList->size_ > CAPACITY) {
            std::cout << "ArrayList does not have enough capacity."
                      << std::endl;
            return;
        }

        for (int i = 0; i < otherList->size_; ++i) {
            data_[size_ + i] = otherList->data_[i];
            otherList->data_[i] = nullptr;
        }

        size_ += otherList->size_;
        otherList->size_ = 0;
    }

    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }

private:
    static const int CAPACITY = 20;

    T* data_[CAPACITY];
    int size_;
};