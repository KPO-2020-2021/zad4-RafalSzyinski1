#ifndef ROTATION_GNUPLOT_H
#define ROTATION_GNUPLOT_H

#include <utility>
#include <vector>
#include <stdexcept>

#include "gplot++.h"
#include "Rectangular.h"

class GNUPlot
{
private:
    Gnuplot plt;
    std::vector<std::string> objects;
public:
    GNUPlot();

    void addWall(const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& startPoint);
    void addRectangular(const Rectangular& rec);
    void draw();
};


#endif //ROTATION_GNUPLOT_H
