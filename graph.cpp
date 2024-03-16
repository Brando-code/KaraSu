/*
 * Created by brando on 06/07/21.
 *
 * Description:
 *  Implementation of a graph relating to a Sudoku puzzle with oreder nxn.
 *
 * Inputs:
 *  nNodes = number of nodes in the graph;
 *  matOrder = sudoku order (i.e. sudoku 4x4, 9x9, 16x16, etc...);
 *  blkOrder = order of every single sudoku's block (i.e. sudoku 4x4 --> block 2x2, sudoku 9x9 --> block 3x3, etc...).
 *
 * Output:
 *  Adjacency matrix.
 */


#include "graph.hpp"
#include <cmath>
#include "IO_data.hpp"
//#include <vector>

Graph::Graph() = default;


matrix Graph::makeAdjMatrix(unsigned int matOrder)
{
    int blkOrder = std::sqrt(matOrder);
    unsigned int nNodes = matOrder * matOrder;

    matrix adjacencyMatrix(nNodes);
    for (int i = 0; i < nNodes; i++)
    {
            adjacencyMatrix[i].resize(nNodes);
    }

    // Map nodes links in rows and columns
    for (unsigned int i = 0; i < nNodes; i++)
    {
        for(unsigned int j = 0; j < nNodes; j++)
        {
            if(j >= (i/matOrder)*matOrder && j < (i/matOrder)*matOrder + matOrder)
            {
                adjacencyMatrix[i][j] = 1.;
            }
            else
            {
                if(j%matOrder == i%matOrder) // set to 1 diagonal elements.
                    adjacencyMatrix[i][j] = 1.;
                else
                    adjacencyMatrix[i][j] = 0;
            }

        }
    }

    // Map nodes links in every single block
    for (unsigned int i = 0; i < nNodes; i++)
    {
        for(unsigned int r = 0; r < blkOrder; r++)
        {
            for(unsigned int k = 0; k < blkOrder; k++)
            {
                if((i/matOrder)%blkOrder == 0 )
                    for(unsigned int j = 0; j < blkOrder; j ++)
                    {
                        adjacencyMatrix[i + matOrder * r][(i/blkOrder)*blkOrder + j + matOrder * k] = 1.;
                    }
            }
        }
    }

    return adjacencyMatrix;
}
