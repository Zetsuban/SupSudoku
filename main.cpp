#include "sudokuGen.h"

#include <iostream>
#include <thread>

/*
 * Sudoku du cul
 * Coucou Romain, ça compile pas sous windows du coup go linux l'OS supérieur.
 */

int main() {
    SudokuBoard board;
    /*
    std::stringstream output;

    for (int i = 0; i < 5000; ++i) {

        board = genBoard();
        //board.display();
        output << board.parser() << '\n';
    }

    std::cout << output.str();
    */

    std::string input;

    board = genBoard();
    board.display();

    while (!board.completed()) {
        std::cout << "Choose row number : ";
        getline(std::cin, input);
        int inputX = std::stoi(input) - 1;
        std::cout << "Choose col number : ";
        getline(std::cin, input);
        int inputY = std::stoi(input) - 1;

        board.turn({inputX, inputY});

        board.display();
    }

    if (board.win()) {
        std::cout << "You WIN !!\n";
    } else {
        std::cout << "YA LOST\n";
    }

    return 0;
}

