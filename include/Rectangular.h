#ifndef ROTATION_RECTANGULAR_H
#define ROTATION_RECTANGULAR_H

#include <vector>
#include <stdexcept>

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

    std::vector<Wall> walls;
public:
    Rectangular() = delete;
    Rectangular(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& z, std::vector<double> _startPoint = std::vector<double>());

    void drawPlot() const;
};


#endif //ROTATION_RECTANGULAR_H
