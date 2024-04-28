//
// Created by groxikm on 28.04.2024.
//
#include "../lib/mass/MassCell.hpp"
#include "../lib/mass/MassCell.cpp"

int main() {
    auto* massCell = new MassCell(123L, 10, 10, 15, 100, 0);

    // test
    massCell->move();
    massCell->move();

    if (massCell->getX()==210 && massCell->getY()==10) return 0;

    return 1;
}
