# pragma once

#include <iostream>
#include "List.h"

template <typename T> // during runtime, map it to whatever data type is being used into a main program
class ArrayList : public List<T> {
 public:

    ArrayList() : size_(0) {
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

        --size_;
    }

    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) return true;
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
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        if (position < 0 || position > size_) {
            std::cout << "Position out of range." << std::endl;
            return;
        }
       for (int i = size_; i > position ; --i) {
           data_[i] = data_[i - 1];
       }
        data_[position] = value;
        ++size_;
    }

    void deleteAnywhere(int position) override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        if (position < 0 || position >= size_) {
            std::cout << "Position out of range." << std::endl;
            return;
        }

        delete data_[position];

        for (int i = position; i < size_-1; ++i ) {
            data_[i] = data_[i + 1];
        }

        --size_;
    }

    void reverse() override {
        int left = 0;
        int right = size_ - 1;
        while (left < right) {
            std::swap(data_[left], data_[right]);
            left++;
            right--;
        }
    }

    void concat(List<T>* other) override {
        ArrayList<T>* otherList = dynamic_cast<ArrayList<T>*>(other);
        if (otherList == nullptr) {
            std::cout << "Error: List types don't match " << std::endl;
            return;
        }
        if (size_ + otherList->size_ <= CAPACITY) {
            for (int i = 0; i < otherList->size_; ++i) {
                data_[size_] = otherList->data_[i];
                size_++;
            }
        }
        else {
            std::cout << "Error: List exceeds capacity " << std::endl;
            return;
        }

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
