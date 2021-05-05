#include "Rectangular.h"
#include <sstream>
#include <utility>


Rectangular::Rectangular(std::vector<double>  _x, std::vector<double>  _y, std::vector<double>  _z, std::vector<double> _startPoint)
                        : x(std::move(_x)), y(std::move(_y)), z(std::move(_z)), startPoint(std::move(_startPoint))
{
    using namespace VectorAction;

    walls.clear();
    if (startPoint.empty())
        startPoint = std::vector<double>(x.size());
    walls.emplace_back(x, y, startPoint);
    walls.emplace_back(x, z, startPoint);
    walls.emplace_back(y, z, startPoint);
    std::vector<double> newPoint = startPoint + x + y + z;
    walls.emplace_back(-x, -y, newPoint);
    walls.emplace_back(-x, -z, newPoint);
    walls.emplace_back(-y, -z, newPoint);
}


void Rectangular::drawPlot()
{

}

Rectangular Rectangular::operator*(const matrix<double>& mat)
{
    using namespace MatrixAction;
    Rectangular ret(mat * x, mat * y, mat * z);
    return ret;
}

