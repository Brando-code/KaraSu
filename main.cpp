#include <iostream>
#include "graph.hpp"
#include "IO_data.hpp"
#include "coloring.hpp"

int main() {

    // Select sudoku puzzle.
    std::string filename ("sudoku_9x9_of_death.txt");
    std::string inputPath = "/home/brando/CLionProjects/KaraSu/sudo_sample/";

    // Load input matrix.
    matrix sudoMat;
    std::ifstream in(inputPath + filename);
    readMatrix(sudoMat, in);
    in.close();
    std::cout << "Solve:" << std::endl;
    printMatrix(sudoMat);

    // Make adjacency matrix.
    unsigned int mOrder = sudoMat.size(); // Sudoku input-matrix order.
    Graph adjMat;
    matrix sudoGraph = adjMat.makeAdjMatrix(mOrder);
    //printMatrix(sudoGraph);

    // Solve sudoku.
    Coloring sudoColor;
    matrix colored = sudoColor.coloringSDO(sudoGraph, sudoMat, mOrder);
    std::cout << "Solution:" << std::endl;
    printMatrix(colored);

    return 0;
}