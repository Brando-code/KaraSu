/*
 * Created by brando on 06/07/21.
 *
 * Description:
 *  Implementation of a graph relating to a Sudoku puzzle with order nxn.
 *
 * Inputs:
 *  nNodes = number of nodes in the graph;
 *  matOrder = sudoku order (i.e. sudoku 4x4, 9x9, 16x16, etc...);
 *  blkOrder = order of every single sudoku's block (i.e. sudoku 4x4 --> block 2x2, sudoku 9x9 --> block 3x3, etc...).
 *
 * Output:
 *  Adjacency matrix.
 */

#ifndef KARASU_GRAPH_HPP
#define KARASU_GRAPH_HPP

#include <vector>
#include "IO_data.hpp"

class Graph
{
 public:
    matrix makeAdjMatrix(unsigned int matOrder);

    Graph();
};
#endif //KARASU_GRAPH_HPP
