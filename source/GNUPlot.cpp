/**
 * @file GNUPlot.cpp
 * Definition of GNUPlot class
 */

#include "GNUPlot.h"

#include "VectorAction.h"

/**
 * Default constructor
 */
GNUPlot::GNUPlot() : plt(), objects(), surfaceColor("#FF00FF"), surfaceFormula("0")
{
}

/**
 * Make and save object wall made from 2 vectors and starting point. \n
 * Using VectorAction.h.
 * @param a first side of the wall
 * @param b second side of the wall
 * @param startPoint point where vectors start
 */
void GNUPlot::addWall(const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& startPoint)
{
    using namespace VectorAction;
    std::vector<double> fig;
    std::stringstream ss;
    ss << " set object " << objects.size() + 1 << " polygon from ";
    fig = startPoint;
    ss << fig << " to ";
    fig = fig + a;
    ss << fig << " to ";
    fig = fig + b;
    ss << fig << " to ";
    fig = fig - a;
    ss << fig << " to ";
    fig = fig - b;
    ss << startPoint;
    ss << " fillstyle transparent solid fillcolor rgb \"#FF0000\"";
    objects.push_back(ss.str());
}

/**
 * Adding rectangular to space. \n
 * Using addWall method and VectorAction.h
 */
void GNUPlot::addRectangular(const Rectangular& rec)
{
    using namespace VectorAction;
    addWall(rec.X(), rec.Y(), rec.StartPoint());
    addWall(rec.X(), rec.Z(), rec.StartPoint());
    addWall(rec.Y(), rec.Z(), rec.StartPoint());
    std::vector<double> newPoint = rec.StartPoint() + rec.X() + rec.Y() + rec.Z();
    addWall(-rec.X(), -rec.Y(), newPoint);
    addWall(-rec.X(), -rec.Z(), newPoint);
    addWall(-rec.Y(), -rec.Z(), newPoint);
}

/**
 * Setup the space and drawing all object. \n
 * At end delete all object.
 */
void GNUPlot::draw()
{
    plt.sendcommand("set ticslevel 0");
    plt.sendcommand("set xyplane at 0");
    plt.sendcommand("set xrange [-2:2]");
    plt.sendcommand("set yrange [-2:2]");
    plt.sendcommand("set zrange [-2:2]");

    for (auto& i : objects)
        plt.sendcommand(i);
    plt.sendcommand("splot " + surfaceFormula +  " linecolor \"" + surfaceColor + "\" ");
    objects.clear();
}

