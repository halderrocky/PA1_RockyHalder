#pragma once
#include "node.h"
#include "List.h"

template <typename T>

class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr) {}

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
    }

    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty" << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
    }

    void addAnywhere(int position, T* value) override {
        Node<T>* fresh = new Node<T>(value);
        Node<T>* current = head_;

        if (position == 0) {
            fresh->next = head_;
            head_ = fresh;
            return;
        }

        for (int i = 0; i < position - 1; i++) {
            if (current != nullptr) {
                current = current->next;
            }
            else {
                std::cout << "Invalid position. Position must be [0," << i << "]" << std::endl;
                return;
            }
        }
        fresh->next = current->next;
        current->next = fresh;
    }

    void deleteAnywhere(int position) override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty" << std::endl;
            return;
        }
        if (position == 0) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
            return;
        }
        Node<T>* current = head_;
        for (int i = 0; i < position - 1; i++) {
            if (current != nullptr) {
                current = current->next;
            }
            else {
                std::cout << "Invalid position. Position must be [0," << i-1 << "]" << std::endl;
                return;
            }
        }

        if (current->next == nullptr) {
            std::cout << "Cannot delete nullptr" << std::endl;
            return;
        }
        Node<T>* doomed = current->next;
        current->next = doomed->next;
        delete doomed->data;
        delete doomed;
    }

    void reverse() override {
        Node<T>* current = head_;
        Node<T>* previous = nullptr;
        while (current != nullptr) {
            Node<T>* saved = current->next;
            current->next = previous;
            previous = current;
            current = saved;
        }
        head_ = previous;
    }

    void concat(List<T>* other) override {
        LinkedList<T>* otherList = dynamic_cast<LinkedList<T>* >(other);
        if (otherList == nullptr) {
            std::cout << "Error: List types don't match" << std::endl;
            return;
        }
        Node<T>* current = head_;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = otherList->head_;
        otherList->head_ = nullptr;
    }

    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }

    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

private:
    Node<T>* head_;
};

