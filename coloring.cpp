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

#include "coloring.hpp"
#include "IO_data.hpp"

matrix Coloring::coloringSDO(matrix adjMat, matrix inputMat, int matOrder)
{
    movetoDiag(inputMat, adjMat, true);

    int nColoredNodes = 0;
    unsigned int nodesToColor = nodesNotCol(adjMat);
    while( nColoredNodes < nodesToColor)
    {
        int max = -1, index = -1;
        for (int i = 0; i < adjMat.size(); ++i)
        {
            if (adjMat[i][i] == 0)
            {
                int sDegree = satDeg(i, adjMat, matOrder);
                if (sDegree > max) { max = sDegree; index = i ; }
                else if (sDegree == max)
                {
                    if (nodeDeg(i, adjMat) > nodeDeg(index, adjMat)) index = i;
                }
            }
        }
        adjMat[index][index] = setColor(index, adjMat, matOrder);
        nColoredNodes++;
    }

    movetoDiag(inputMat, adjMat, false);

    return inputMat;
}

/*
 * Description:
 *  Node degree calculator.
 *
 * Inputs:
 *  row = row index of the node considered;
 *  adjMat = adjacency matrix.
 *
 * Output:
 *  Node degree.
 */
unsigned int Coloring::nodeDeg(int row, matrix adjMat)
{
    unsigned int sum = 0;
    for (int i = 0; i < adjMat.size(); ++i) sum += adjMat[row][i];
    return sum - adjMat[row][row];
}

/*
 * Description:
 *  Saturation degree calculator for a node in the graph.
 *
 * Inputs:
 *  row = row index of the node considered;
 *  adjMat = adjacency matrix;
 *  matOrder: matrix order of the sudoku puzzle.
 *
 * Outputs:
 *  Saturartion degree of the node considered.
 */
unsigned int Coloring::satDeg(int row, matrix adjMat, int matOrder)
{
    int satDegree = 0;
    for (int i = 1; i <= matOrder; ++i) // for each available color
    {
        for (int j = 0; j <= adjMat.size(); ++j)
        {
            if (j == row) continue; // if diagonal element jump to j + 1.
            if (adjMat[row][j] == 1)
            {
                if (adjMat[j][j] == i) { satDegree++; break; }
            }
        }
    }
    return satDegree;
}

/*
 * Description:
 *  Set the first available color for one node uncolored.
 *
 * Inputs:
 *  row = row index of the node considered;
 *  adjMat = adjacency matrix;
 *  matOrder: matrix order of the sudoku puzzle.
 *
 * Outputs:
 *  Saturartion degree of the node considered.
 */
unsigned int Coloring::setColor(int row, matrix adjMat, int matOrder)
{
    int color = 0;
    for (int i = 1; i <= matOrder; ++i) // for each available color
    {
        int loop = 0; // current loop number.
        for (int j = 0; j < adjMat.size() ; ++j)
        {
            loop++;
            if (j == row) continue; // if diagonal element jump to j + 1.
            if (adjMat[row][j] == 1)
            {
                if (adjMat[j][j] == i) {color = 0 ; break;}
                else color = i;
            }
        }
        if (color != 0) // if the last element has the chosen color, don't break color searching.
            if (loop == adjMat.size()) break; // if the first available color is found stop searching.
    }
    return color;
}

/*
 * Description:
 *  Number of not colored nodes calculator.
 *
 * Inputs:
 *  adjMat = adjacency matrix.
 *
 * Outputs:
 *  Number of uncolored nodes.
 */
unsigned int Coloring::nodesNotCol(matrix adjMat)
{
    unsigned int sum = 0;
    for (int i = 0; i < adjMat.size(); ++i) if (adjMat[i][i] == 0) sum ++;
    return sum;
}

/*
 // Welsh-Powell algorithm implementation. Don't works.

matrix Coloring::coloringWP(matrix adjMat, matrix inputMat)
{
    movetoDiag(inputMat, adjMat, true);

    unsigned int color = 1.;
    for (unsigned int i = 0; i < adjMat.size(); ++i)
    {
        for (unsigned int j = 0; j < adjMat.size(); ++j)
        {
            if (adjMat[i][j] == 0)
            {
                if (adjMat[i][i] > 0 && adjMat[j][j] == 0) { adjMat[j][j] = adjMat[i][i]; }
                if (adjMat[i][i] == 0 && adjMat[j][j] == 0) { adjMat[j][j] = color; }
            }
        }
        ++color;
    }

    movetoDiag(inputMat, adjMat, false);

    return inputMat;
}*/


