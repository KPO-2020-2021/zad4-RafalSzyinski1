#include "Rectangular.h"
#include <sstream>
#include <utility>


Rectangular::Rectangular(std::vector<double>  _x, std::vector<double>  _y, std::vector<double>  _z, std::vector<double> _startPoint)
                        : x(std::move(_x)), y(std::move(_y)), z(std::move(_z)), startPoint(std::move(_startPoint))
{
    if (startPoint.empty())
        startPoint = std::vector<double>(x.size());
    if (x.size() != y.size() || x.size() != z.size() || x.size() != startPoint.size())
        throw std::invalid_argument("ERROR Rectangular: x.size() != y.size() || x.size() != z.size() || x.size() != startPoint.size()");
}

bool operator==(const Rectangular& rec1, const Rectangular& rec2)
{
    if ((rec1.x == rec2.x) && (rec1.y == rec2.y) && (rec1.z == rec2.z) && (rec1.startPoint == rec2.startPoint))
        return true;
    return false;
}

Rectangular Rectangular::operator*(const matrix<double>& mat) const
{
    using namespace MatrixAction;
    Rectangular ret(mat * x, mat * y, mat * z, startPoint);
    return ret;
}

Rectangular Rectangular::operator+(const std::vector<double>& vec) const
{
    using namespace VectorAction;
    Rectangular ret(x, y, z, startPoint + vec);
    return ret;
}

const std::vector<double>& Rectangular::X() const
{
    return x;
}

const std::vector<double>& Rectangular::Y() const
{
    return y;
}

const std::vector<double>& Rectangular::Z() const
{
    return z;
}

const std::vector<double>& Rectangular::StartPoint() const
{
    return startPoint;
}

