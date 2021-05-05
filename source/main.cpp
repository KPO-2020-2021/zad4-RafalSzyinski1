#include "Rectangular.h"
#include "MatrixAction.h"

#include <chrono>
#include <thread>

using namespace MatrixAction;

Gnuplot plt{};

void drawRectangular(const Rectangular& rec)
{
    using namespace VectorAction;

    plt.sendcommand("set ticslevel 0");
    plt.sendcommand("set xyplane at 0");
    plt.sendcommand("set view 69,74");
    std::stringstream range;
    range << "set xrange [-2:2]" << std::endl;
    range << "set yrange [-2:2]" << std::endl;
    range << "set zrange [-2:2]" << std::endl;

    plt.sendcommand(range.str());


    std::vector<double> fig;

    for (std::size_t i = 0; i < rec.walls.size(); ++i)
    {
        std::stringstream ss;
        ss << " set object " << i + 1 << " polygon from ";
        fig = rec.walls.at(i).startPoint;
        ss << fig << " to ";
        fig = fig + rec.walls.at(i).a;
        ss << fig << " to ";
        fig = fig + rec.walls.at(i).b;
        ss << fig << " to ";
        fig = fig + -rec.walls.at(i).a;
        ss << fig << " to ";
        fig = fig + -rec.walls.at(i).b;
        ss << rec.walls.at(i).startPoint;
        ss << " fillstyle transparent solid fillcolor rgb \"#FF0000\"";
        plt.sendcommand(ss.str());
    }

    plt.sendcommand("splot 0 linecolor \"#FFFF0000\" ");
}

int main()
{
    std::vector<double> x = {1, 0, 0};
    std::vector<double> y = {0, 1, 0};
    std::vector<double> z = {0, 0, 1};
    matrix<double> mat = {{1, 0, 0}, {0, std::cos(M_PI/180 * 2), -std::sin(M_PI/180 * 2)}, {0, std::sin(M_PI/180 * 2), std::cos(M_PI/180 * 2)}};
    Rectangular r(x, y, z);
    while (true)
    {
        drawRectangular(r);
        r = r * mat;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

}