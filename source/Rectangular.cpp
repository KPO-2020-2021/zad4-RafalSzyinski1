#include "Rectangular.h"
#include "VectorAction.h"
#include "gplot++.h"

#include <sstream>
#include <utility>

//TODO negative of vector / find max and min

Rectangular::Rectangular(const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& z, std::vector<double> _startPoint)
{
    using namespace VectorAction;
    if (_startPoint.empty())
        _startPoint = std::vector<double>(x.size());
    walls.emplace_back(x, y, _startPoint);
    walls.emplace_back(x, z, _startPoint);
    walls.emplace_back(y, z, _startPoint);
    std::vector<double> newPoint = _startPoint + x + y + z;
    walls.emplace_back(std::vector<double>(x.size()) - x, std::vector<double>(y.size()) - y, newPoint);
    walls.emplace_back(std::vector<double>(x.size()) - x, std::vector<double>(z.size()) - z, newPoint);
    walls.emplace_back(std::vector<double>(y.size()) - y, std::vector<double>(z.size()) - z, newPoint);
}


void Rectangular::drawPlot() const
{
    using namespace VectorAction;
    Gnuplot plt{};

    plt.sendcommand("set ticslevel 0");
    plt.sendcommand("set xyplane at 0");
    plt.sendcommand("set view 69,74");

    std::vector<double> fig;

    for (std::size_t i = 0; i < walls.size(); ++i)
    {
        std::stringstream ss;
        ss << " set object " << i + 1 << " polygon from ";
        fig = walls.at(i).startPoint;
        ss << fig << " to ";
        fig = fig + walls.at(i).a;
        ss << fig << " to ";
        fig = fig + walls.at(i).b;
        ss << fig << " to ";
        fig = fig + (std::vector<double>(walls.at(i).a.size()) - walls.at(i).a);
        ss << fig << " to ";
        fig = fig + (std::vector<double>(walls.at(i).b.size()) - walls.at(i).b);
        ss << walls.at(i).startPoint;
        ss << " fillstyle transparent solid fillcolor rgb \"#FF0000\"";
        plt.sendcommand(ss.str());
    }
    plt.sendcommand("set xrange [-1:1]");
    plt.sendcommand("set yrange [-1:1]");
    plt.sendcommand("set zrange [-1:1]");
    plt.sendcommand("splot 0 linecolor \"#FFFF0000\" ");
}
