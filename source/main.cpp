#include "Rectangular.h"
#include "GNUPlot.h"

#include <chrono>
#include <thread>
#include <iostream>

using namespace VectorAction;
using namespace MatrixAction;

int main()
{
    double temp = 0;
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> z;
    std::vector<double> startPoint;
    std::cout << "Rotation3D" << std::endl;
    std::cout << "Rectangular initialization" << std::endl;
    std::cout << "Enter the vector x: ";
    for (int i = 0; i < 3; ++i)
        if(!(std::cin >> temp))
            throw std::invalid_argument("std::invalid_argument x");
        else
            x.push_back(temp);

    std::cout << "Enter the vector y: ";
    for (int i = 0; i < 3; ++i)
        if(!(std::cin >> temp))
            throw std::invalid_argument("std::invalid_argument y");
        else
            y.push_back(temp);

    std::cout << "Enter the vector z: ";
    for (int i = 0; i < 3; ++i)
        if(!(std::cin >> temp))
            throw std::invalid_argument("std::invalid_argument z");
        else
            z.push_back(temp);

    std::cout << "Enter the vector start point: ";
    for (int i = 0; i < 3; ++i)
        if(!(std::cin >> temp))
            throw std::invalid_argument("std::invalid_argument start point");
        else
            startPoint.push_back(temp);

    char option = '0';
    GNUPlot plt;
    Rectangular rec(x, y, z, startPoint);
    matrix<double> mat = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<double> vec = {0, 0, 0};
    int xAngle = 0, yAngle = 0, zAngle = 0;
    int repeats = 1;
    const double a = M_PI/180;

    while (option != '7')
    {
        std::cout << "Menu" << std::endl;
        std::cout << "1 - rotation" << std::endl;
        std::cout << "2 - display rotation matrix" << std::endl;
        std::cout << "3 - translation" << std::endl;
        std::cout << "4 - display translation vector" << std::endl;
        std::cout << "5 - display rectangular" << std::endl;
        std::cout << "6 - animate" << std::endl;
        std::cout << "7 - end" << std::endl;
        std::cin >> option;

        switch (option)
        {
            case '1':
                std::cout << "Rotation matrix initialization" << std::endl;
                std::cout << "Enter x angle: ";
                if (!(std::cin >> xAngle))
                    throw std::invalid_argument("Something wrong");
                std::cout << "Enter y angle: ";
                if (!(std::cin >> yAngle))
                    throw std::invalid_argument("Something wrong");
                std::cout << "Enter z angle: ";
                if (!(std::cin >> zAngle))
                    throw std::invalid_argument("Something wrong");
                xAngle = xAngle % 360;
                yAngle = yAngle % 360;
                zAngle = zAngle % 360;
                mat = matrix<double>({{std::cos(a * zAngle), -std::sin(a * zAngle), 0}, {std::sin(a * zAngle), std::cos(a * zAngle), 0}, {0, 0, 1}})
                        * matrix<double>({{std::cos(a * yAngle), 0, std::sin(a * yAngle)}, {0, 1, 0}, {-std::sin(a * yAngle), 0, std::cos(a * yAngle)}})
                        * matrix<double>({{1, 0, 0}, {0, std::cos(a * xAngle), -std::sin(a * xAngle)}, {0, std::sin(a * xAngle), std::cos(a * xAngle)}});
                break;
            case '2':
                std::cout << "Rotation matrix" << std::endl;
                std::cout << mat << std::endl;
                break;
            case '3':
                std::cout << "Enter the translation vector: ";
                for (int i = 0; i < 3; ++i)
                    if(!(std::cin >> temp))
                        throw std::invalid_argument("std::invalid_argument translation vector");
                    else
                        vec.at(i) = temp;
                break;
            case '4':
                std::cout << "Translation vector" << std::endl;
                std::cout << vec << std::endl;
                break;
            case '5':
                std::cout << "Rectangular" << std::endl;
                std::cout << "Vector x: " << rec.X() << std::endl;
                std::cout << "Vector y: " << rec.Y() << std::endl;
                std::cout << "Vector z: " << rec.Z() << std::endl;
                std::cout << "Vector startPoint: " << rec.StartPoint() << std::endl;
                break;
            case '6':
                std::cout << "Number of repeats: ";
                if(!(std::cin >> repeats))
                    throw std::invalid_argument("std::invalid_argument repeats");
                std::cout << "Animation" << std::endl;
                for (int i = 0; i < (repeats + 1); ++i)
                {
                    plt.addRectangular(rec);
                    plt.draw();
                    rec = rec * mat;
                    rec = rec + vec;
                    std::this_thread::sleep_for(std::chrono::milliseconds(250));
                    std::cout << rec.StartPoint() << std::endl;
                }
                mat = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
                vec = {0, 0, 0};
                xAngle = 0, yAngle = 0, zAngle = 0;
                break;
            case '7':
                std::cout << "Exit" << std::endl;
                break;
            default:
                std::cout << "There is no such option" << std::endl;
                break;
        }
    }
}