#include <iostream>
#include "List.h"
#include "Player.h"
using namespace std;

int main() {
    // ---- Part 1: required test harness, do not modify ----
    cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    cout << endl << "== List<int>: concat ==" << endl;
    unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----

    cout << endl << "== Uno scene ==" << endl;
     unique_ptr<List<Player>> table = makeList<Player>();
    Player* p1 = new Player(1, "Alice");
    Player* p2 = new Player(2, "Bob");
    Player* p3 = new Player(3, "Jack");
    table->addFront(p1);
    table->addFront(p2);
    table->addFront(p3);
    p1->push(new Card("Green", 4));
    p1->push(new Card("Yellow", 4));
    p2->push(new Card("Yellow", 2));
    p2->push(new Card("Red", 6));
    p3->push(new Card("Red", 5));
    p3->push(new Card("Blue", 2));
    Card* p1Played = p1->pop();
    if (p1Played != nullptr) {
         cout << "Alice Played " << *p1Played << endl;
         delete p1Played;
    }
     Player* p4 = new Player(4, "Charlie");
     table->addAnywhere(1, p4);
     p4->push(new Card("Green", 6));
     p4->push(new Card("Red", 1));
     cout << "List before reverse" << endl;
     table->print();
     table->reverse();
     cout << "List after reverse" << endl;
     table->print();
     Card* p4Played = p4->pop();
     Card* p4Played1 = p4->pop();
     if (p4Played != nullptr) {
          cout << "Charlie Played " <<  *p4Played << endl;
          delete p4Played;
     }
     if (p4Played1 != nullptr) {
          cout << "Charlie Played " << *p4Played1 << endl;
          delete p4Played1;
    }
    table->deleteAnywhere(2);
    cout << "Charlie ran out of cards and is eliminated" << endl;
    cout << "Charlie left the game. Updated table: ";
    table->print();

    cout << "*-----------------*" << endl;
     unique_ptr<List<Player>> table2 = makeList<Player>();
    Player* p5 = new Player(7, "David");
    Player* p6 = new Player(6, "Elena");
    Player* p7 = new Player(5, "Felix");
    table2->addFront(p5);
    p5->push(new Card("Green", 3));
    p5->push(new Card("Blue", 5));
    table2->addFront(p6);
    p6->push(new Card("Yellow", 1));
    p6->push(new Card("Red", 3));
    table2->addFront(p7);
    p7->push(new Card("Red", 2));
    p7->push(new Card("Green", 6));
    Card* p5Played = p5->pop();
    if (p5Played != nullptr) {
         cout << "David Played " << *p5Played << endl;
         delete p5Played;
    }
    cout << "List before concat" << endl;
    table->print();
    table2->print();
    table->concat(table2.get());
    cout << "List after concat" << endl;
    table->print();
    table2->print();




    return 0;
}
