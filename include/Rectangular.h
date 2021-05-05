#ifndef ROTATION_RECTANGULAR_H
#define ROTATION_RECTANGULAR_H

#include <vector>
#include <stdexcept>
#include "gplot++.h"
#include "MatrixAction.h"

class Rectangular
{
private:
    struct Wall
    {
        std::vector<double> a;
        std::vector<double> b;
        std::vector<double> startPoint;

        Wall() = delete;
        Wall(std::vector<double> _a, std::vector<double> _b, std::vector<double> _startPoint) : a(std::move(_a)), b(std::move(_b)), startPoint(std::move(_startPoint))
        {
            if (startPoint.empty())
                startPoint = std::vector<double>(a.size());
            if ((a.size() != b.size()) || (a.size() != startPoint.size()))
                throw std::invalid_argument("ERROR Wall: (a.size() != b.size()) || (a.size() != startPoint.size())");
        }
    };

private:
    std::vector<Wall> walls;
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> z;
    std::vector<double> startPoint;

    friend void drawRectangular(const Rectangular& rec);
public:
    Rectangular() = delete;
    Rectangular(std::vector<double>  _x, std::vector<double>  _y, std::vector<double>  _z, std::vector<double> _startPoint = std::vector<double>());

    Rectangular operator*(const matrix<double>& mat);

    void drawPlot();
};


#endif //ROTATION_RECTANGULAR_H
