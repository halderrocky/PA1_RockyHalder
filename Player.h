#pragma once
#include <ostream>
#include <string>

#include "Card.h"
#include "Stack.h"

class Player {
public:
    Player(int id, const std::string& name)
        : id_(id), name_(name) {
        hand_ = new Stack<Card>();
    }

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }

    void push(Card* card) {
        hand_->push(card);
    }

    Card* pop() {
        return hand_->pop();
    }

    ~Player() {
        delete hand_;
    }

private:
    int id_;
    std::string name_;
    Stack<Card>* hand_;
};
