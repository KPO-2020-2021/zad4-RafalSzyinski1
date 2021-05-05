//
// Created by rafik on 22.04.2021.
//

#ifndef ROTATION_MATRIXACTION_H
#define ROTATION_MATRIXACTION_H

#include "VectorAction.h"

template<typename T>
using matrix = std::vector< std::vector<T> >;

namespace MatrixAction
{
    template<typename T>
    matrix<T> operator+(const matrix<T>& mat1, const matrix<T>& mat2);

    template<typename T>
    matrix<T> operator*(const matrix<T>& mat, double sc);

    template<typename T>
    matrix<T> operator*(double sc, const matrix<T>& mat);

    template<typename T>
    matrix<T> operator-(const matrix<T>& mat1, const matrix<T>& mat2);

    template<typename T>
    std::vector<T> operator*(const matrix<T>& mat, const std::vector<T>& vec);

    template<typename T>
    std::vector<T> operator*(const std::vector<T>& vec, const matrix<T>& mat);

    template<typename T>
    matrix<T> operator*(const matrix<T>& mat1, const matrix<T>& mat2);

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const matrix<T>& mat);
}   //MartixAction

template<typename T>
matrix<T> MatrixAction::operator+(const matrix<T>& mat1, const matrix<T>& mat2)
{
    using VectorAction::operator+;
    if (mat1.size() != mat2.size())
        throw std::out_of_range("Matrix ERROR sum operator: mat1.size() != mat2.size()");

    matrix<T> ret;

    for (int i = 0; i < mat1.size(); ++i)
        ret.push_back(mat1[i] + mat2[i]);


    return ret;
}

template<typename T>
matrix<T> MatrixAction::operator-(const matrix<T>& mat1, const matrix<T>& mat2)
{
    using VectorAction::operator-;
    if (mat1.size() != mat2.size())
        throw std::out_of_range("Matrix ERROR diff operator: mat1.size() != mat2.size()");

    matrix<T> ret;

    for (int i = 0; i < mat1.size(); ++i)
        ret.push_back(mat1[i] - mat2[i]);

    return ret;
}

template<typename T>
matrix<T> MatrixAction::operator*(const matrix<T>& mat, double sc)
{
    matrix<T> ret;
    for (int i = 0; i < mat.size(); ++i)
    {
        ret.push_back(std::vector<T>());
        for (int j = 0; j < mat[i].size(); ++j)
            ret[i].push_back(mat[i][j] * sc);
    }

    return ret;
}

template<typename T>
matrix<T> MatrixAction::operator*(double sc, const matrix<T>& mat)
{
    return mat * sc;
}

template<typename T>
std::vector<T> MatrixAction::operator*(const matrix<T>& mat, const std::vector<T>& vec)
{
    using VectorAction::operator*;
    for (auto& i : mat)
        if (i.size() != vec.size())
            throw std::out_of_range("Matrix ERROR multiVec: i.size() != vec.size()");

    std::vector<T> ret(mat.size());
    for (int i = 0; i < mat.size(); ++i)
        ret[i] = mat[i] * vec;

    return ret;
}

template<typename T>
std::vector<T> MatrixAction::operator*(const std::vector<T>& vec, const matrix<T>& mat)
{
    using VectorAction::operator*;

    if (vec.size() != mat.size())
        throw std::out_of_range("Matrix ERROR multiVec: vec.size() != mat.size()");

    std::vector<T> ret;

    if (mat.empty())
        return std::vector<T>();

    for (int j = 0; j < mat[0].size(); ++j)
    {
        std::vector<T> temp;
        for (int k = 0; k < mat.size(); ++k)
            temp.push_back(mat.at(k).at(j));
        ret.push_back(vec * temp);
    }

    return ret;
}

template<typename T>
matrix<T> MatrixAction::operator*(const matrix<T>& mat1, const matrix<T>& mat2)
{
    std::size_t widthOfMatOne = mat2.size();
    std::size_t heightOfMatOne = mat1.size();

    for (auto& i : mat1)
        if (i.size() != widthOfMatOne)
            throw std::out_of_range("Matrix ERROR multiMat: i.size() != widthOfMatOne");

    for(auto& j : mat2)
        if (j.size() != heightOfMatOne)
            throw std::out_of_range("Matrix ERROR multiMat: j.size() != heightOfMatOne");


    matrix<T> ret(heightOfMatOne, std::vector<T>(heightOfMatOne));

    for (int i = 0; i < heightOfMatOne; ++i)
        for (int j = 0; j < heightOfMatOne; ++j)
            for (int k = 0; k < widthOfMatOne; ++k)
                ret[i][j] += mat1[i][k] * mat2[k][j];

    return ret;
}

template<typename T>
std::ostream& MatrixAction::operator<<(std::ostream& os, const matrix<T>& mat)
{
    using VectorAction::operator<<;
    for (auto& i : mat)
        os << i << std::endl;
    return os;
}

#endif //ROTATION_MATRIXACTION_H
