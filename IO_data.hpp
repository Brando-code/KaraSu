/*
 * Created by brando on 07/07/21.
 *
 * Description:
 *  Collection of auxiliary codes for loading, printing and managing data.
*/

#ifndef KARASU_IO_DATA_HPP
#define KARASU_IO_DATA_HPP

#include <sstream>
#include "fstream"
#include <vector>
#include <iostream>
#include <string>

// Matrix type definition.
typedef std::vector<std::vector<unsigned int>> matrix;

// Read matrix from file.
template<class T >std::istream& readMatrix(std::vector<std::vector<T>>& outputMatrix, std::istream& inStream)
{
    if (inStream)
    {
        std::string line;

        while (std::getline(inStream, line))
        {
            outputMatrix.emplace_back();

            // Break down the row into column values
            std::stringstream split(line);
            int value;

            while (split >> value) { outputMatrix.back().push_back(value); }
        }
    }
    return inStream;
}

// Print matrix.
template<class T > void printMatrix(std::vector<std::vector<T>>& inputMatrix)
{
    for (int i = 0; i < inputMatrix.size(); ++i)
    {
        for (int j = 0; j < inputMatrix.size(); ++j)
        {
            std::cout << inputMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Move matrix1 elements to diagonal of matrix2 and vice-versa.
template<class T > void movetoDiag(std::vector<std::vector<T>>& matrix1, std::vector<std::vector<T>>& matrix2, bool toDiag)
{
    unsigned int row = 0.; // row index of matrix2
    for (unsigned int i = 0; i < matrix1.size(); ++i)
    {
        for (unsigned int j = 0; j < matrix1.size(); ++j)
        {
            if (toDiag) matrix2[row][row] = matrix1[i][j]; // move elements from matrix1 to matrix2's diagonal.
            else { matrix1[i][j] = matrix2[row][row]; } // move elements from matrix2's diagonal to matrix1.
            ++row;
        }
    }
}


#endif //KARASU_IO_DATA_HPP
