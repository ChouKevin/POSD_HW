#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <math.h>
#include "shape.h"
#include "find_area_visitor.h"
#include <iostream>
class Ellipse: public Shape{
public:
    Ellipse(double a, double b):_a(a), _b(b){
        std::cout << "Ellipse:" << this->area() << std::endl;
    }
    double area() const{
        return M_PI * this->_a * this->_b;
    }
    double perimeter() const{
        return  2 * M_PI * sqrt((powf(this->_a, 2) + powf(this->_b, 2)) / 2);
    }
private:
    double _a, _b;
};

#endif