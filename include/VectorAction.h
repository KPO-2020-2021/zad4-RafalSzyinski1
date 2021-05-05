//
// Created by rafik on 21.04.2021.
//

#ifndef ROTATION2D_VECTORACTION_H
#define ROTATION2D_VECTORACTION_H


#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

template<typename T>
bool operator==(const std::vector<T>& vec1, const std::vector<T>& vec2)
{
    if (vec1.size() != vec2.size())
        return false;

    const int DEC_PLACE = 10;
    for (int i = 0; i < vec1.size(); ++i)
        if (std::abs(vec1.at(i) - vec2.at(i)) > std::pow(10, DEC_PLACE))
            return false;
    return true;
}

namespace VectorAction
{
    template<typename T>
    std::vector<T> operator*(const std::vector<T>& vec, const T& sc);

    template<typename T>
    std::vector<T> operator*(const T& sc, const std::vector<T>& vec);

    //ScalarProduct
    template<typename T>
    double operator*(const std::vector<T>& vec1, const std::vector<T>& vec2);

    template<typename T>
    std::vector<T> operator+(const std::vector<T>& vec1, const std::vector<T>& vec2);

    template<typename T>
    std::vector<T> operator-(const std::vector<T>& vec1, const std::vector<T>& vec2);

    template<typename T>
    std::vector<T> operator-(const std::vector<T>& vec);

    template<typename T>
    double abs(const std::vector<T>& vec);

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec);
}   //VectorAction


template<typename T>
std::vector<T> VectorAction::operator*(const std::vector<T>& vec, const T& sc)
{
    std::vector<T> ret;
    for (auto& i : vec)
        ret.push_back(i * sc);
    return ret;
}

template<typename T>
std::vector<T> VectorAction::operator*(const T& sc, const std::vector<T>& vec)
{
    return vec * sc;
}

template<typename T>
double VectorAction::operator*(const std::vector<T>& vec1, const std::vector<T>& vec2)
{
    if (vec1.size() != vec2.size())
        throw std::out_of_range("Vector ERROR ScalarProduct: vec1.size() != vec2.size()");
    double ret = 0;

    for (int i = 0; i < vec1.size(); ++i)
        ret += vec1[i] * vec2[i];

    return ret;
}

template<typename T>
std::vector<T> VectorAction::operator+(const std::vector<T>& vec1, const std::vector<T>& vec2)
{
    if (vec1.size() != vec2.size())
        throw std::out_of_range("Vector ERROR Sum Operator: vec1.size() != vec2.size()");


    std::vector<T> ret;
    for (int i = 0; i < vec1.size(); ++i)
        ret.push_back(vec1[i] + vec2[i]);

    return ret;
}

template<typename T>
std::vector<T> VectorAction::operator-(const std::vector<T>& vec1, const std::vector<T>& vec2)
{
    if (vec1.size() != vec2.size())
        throw std::out_of_range("Vector ERROR Sum Operator: vec1.size() != vec2.size()");


    std::vector<T> ret;
    for (int i = 0; i < vec1.size(); ++i)
        ret.push_back(vec1[i] - vec2[i]);

    return ret;
}

template<typename T>
double VectorAction::abs(const std::vector<T>& vec)
{
    double ret = vec * vec;
    return std::sqrt(ret);
}

template<typename T>
std::ostream& VectorAction::operator<<(std::ostream& os, const std::vector<T>& vec)
{
    std::ios::fmtflags old_flags = os.flags();

    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        os << std::fixed << std::setprecision(10) << vec.at(i);
        if (i < vec.size() - 1)
            os << ',';
    }
    os.setf(old_flags);
    return os;
}

template<typename T>
std::vector<T> VectorAction::operator-(const std::vector<T>& vec)
{
    std::vector<T> ret;
    for (auto& i : vec)
        ret.push_back(-i);
    return ret;
}


#endif //ROTATION2D_VECTORACTION_H
