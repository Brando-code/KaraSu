/*
 * Created by brando on 07/07/21.
 *
 * Description:
 *  Solver algorithm based on coloring graph theory. For this purpose the implementation proposed by
 *  A.O. Hussein et all (American Journal of Mathematics and Statistics 2 (4): 439-441, 2006
 *  ISSN 1549-3636) is used.
 *
 * Inputs:
 *  adjMat: adjacency matrix;
 *  inputMat: sudoku puzzle;
 *  matOrder: matrix order of the sudoku puzzle.
 *
 * Output:
 *  matrix of sudoku solution.
*/

#ifndef KARASU_COLORING_HPP
#define KARASU_COLORING_HPP

#include "graph.hpp"

class Coloring
{
    public:
        //matrix coloringWP (matrix adjMat, matrix inputMat);
        matrix coloringSDO(matrix adjMat, matrix inputMat, int matOrder);
        unsigned int nodeDeg(int row, matrix adjMat);
        unsigned int nodesNotCol(matrix adjMat);
        unsigned int satDeg(int row, matrix adjMat, int matOrder);
        unsigned int setColor(int row, matrix adjMat, int matOrder);
};

#endif //KARASU_COLORING_HPP
