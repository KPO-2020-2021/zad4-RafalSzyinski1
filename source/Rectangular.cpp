/**
 * @file Rectangular.cpp
 * Definition of Rectangular class
 */
#include "Rectangular.h"
#include <sstream>
#include <utility>  

/**
 * Single class constructor.
 */
Rectangular::Rectangular(std::vector<double>  _x, std::vector<double>  _y, std::vector<double>  _z, std::vector<double> _startPoint)
                        : x(std::move(_x)), y(std::move(_y)), z(std::move(_z)), startPoint(std::move(_startPoint))
{
    if (startPoint.empty())
        startPoint = std::vector<double>(x.size());
    if (x.size() != y.size() || x.size() != z.size() || x.size() != startPoint.size())
        throw std::invalid_argument("ERROR Rectangular: x.size() != y.size() || x.size() != z.size() || x.size() != startPoint.size()");
}

/**
 * Function comparing two Rectangular. \n
 * Using operator== from VectorAction.h.
 */
bool operator==(const Rectangular& rec1, const Rectangular& rec2)
{
    if ((rec1.x == rec2.x) && (rec1.y == rec2.y) && (rec1.z == rec2.z) && (rec1.startPoint == rec2.startPoint))
        return true;
    return false;
}

/**
 * Multiplication by matrix. Multiply every vector of Rectangular by mat. \n
 * Using MatrixAction.h.
 */
Rectangular Rectangular::operator*(const matrix<double>& mat) const
{
    using namespace MatrixAction;
    Rectangular ret(mat * x, mat * y, mat * z, mat * startPoint);
    return ret;
}

/**
 * Translation by vector. Adding vector to starting point of Rectangular. \n
 * Using VectorAction.h
 */
Rectangular Rectangular::operator+(const std::vector<double>& vec) const
{
    using namespace VectorAction;
    Rectangular ret(x, y, z, startPoint + vec);
    return ret;
}

/**
 * @return const vector x.
 */
const std::vector<double>& Rectangular::X() const
{
    return x;
}

/**
 * @return const vector y.
 */
const std::vector<double>& Rectangular::Y() const
{
    return y;
}

/**
 * @return const vector z.
 */
const std::vector<double>& Rectangular::Z() const
{
    return z;
}

/**
 * @return const vector startPoint.
 */
const std::vector<double>& Rectangular::StartPoint() const
{
    return startPoint;
}

