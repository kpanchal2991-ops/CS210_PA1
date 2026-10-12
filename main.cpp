#include <iostream>
#include "List.h"
#include "PLayer.h"

int main() {
    // Part 1: required test harness
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;

    std::unique_ptr<List<int>> nums = makeList<int>();

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

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;

    std::unique_ptr<List<int>> more = makeList<int>();

    more->addFront(new int(2));
    more->addFront(new int(1));

    more->print();

    nums->concat(more.get());

    nums->print();
    more->print();

    // Part 2: Uno scene
    std::unique_ptr<List<Player>> table = makeList<Player>();

    table->addFront(new Player(3, "player_3"));
    table->addFront(new Player(2, "player_2"));
    table->addFront(new Player(1, "player_1"));

    table->print();

    table->addAnywhere(2, new Player(4, "player_4"));
    table->print();

    std::cout << "Before reverse: ";
    table->print();

    table->reverse();

    std::cout << "After reverse: ";
    table->print();

    table->deleteAnywhere(1);
    table->print();

    std::unique_ptr<List<Player>> secondTable = makeList<Player>();

    secondTable->addFront(new Player(6, "player_6"));
    secondTable->addFront(new Player(5, "player_5"));

    std::cout << "Second table before concat: ";
    secondTable->print();

    table->concat(secondTable.get());

    table->print();

    std::cout << "Second table after concat: ";
    secondTable->print();

    return 0;
}