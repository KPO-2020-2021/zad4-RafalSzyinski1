#include "Rectangular.h"
#include "MatrixAction.h"
#include "GNUPlot.h"

#include <chrono>
#include <thread>

int main()
{
    std::vector<double> x = {1, 0, 0};
    std::vector<double> y = {0, 1, 0};
    std::vector<double> z = {0, 0, 1};
    matrix<double> mat = {{1, 0, 0}, {0, std::cos(M_PI/180 * 2), -std::sin(M_PI/180 * 2)}, {0, std::sin(M_PI/180 * 2), std::cos(M_PI/180 * 2)}};
    Rectangular r(x, y, z);
    std::vector<double> vec = {0.1, 0, 0};
    GNUPlot plot;
    while (true)
    {
        plot.addRectangular(r);
        plot.draw();
        r = r * mat;
        r = r + vec;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

}