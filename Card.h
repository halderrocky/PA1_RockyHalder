#pragma once
#include <ostream>
#include <string>
#include <type_traits>

class Card {

public:
    Card(std::string color, int rank) : color_(color), rank_(rank) {}



    friend std::ostream& operator<<(std::ostream& out, const Card& c) {
        return out << c.color_ << " " << c.rank_;
    }

private:
    std::string color_;
    int rank_;

};
