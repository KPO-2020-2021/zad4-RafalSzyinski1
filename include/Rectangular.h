#ifndef ROTATION_RECTANGULAR_H
#define ROTATION_RECTANGULAR_H

#include "MatrixAction.h"

class Rectangular
{
private:
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> z;
    std::vector<double> startPoint;
public:
    Rectangular() = delete;
    Rectangular(std::vector<double>  _x, std::vector<double>  _y, std::vector<double>  _z, std::vector<double> _startPoint = std::vector<double>());

    friend bool operator==(const Rectangular& rec1, const Rectangular& rec2);

    Rectangular operator*(const matrix<double>& mat) const;
    Rectangular operator+(const std::vector<double>& vec) const;

    const std::vector<double>& X() const;
    const std::vector<double>& Y() const;
    const std::vector<double>& Z() const;
    const std::vector<double>& StartPoint() const;
};


#endif //ROTATION_RECTANGULAR_H
