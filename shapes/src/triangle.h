
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <cmath>
#include <vector>
#include <iostream>
#include "shape.h"
using namespace std;

class Triangle : public Shape{
public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3):_x1(x1), _x2(x2), _x3(x3), _y1(y1), _y2(y2), _y3(y3){
        this->isTriangle();
    }
    double area() const{
        return abs(_x1*_y2+_x2*_y3+_x3*_y1-
        _y1*_x2-_y2*_x3-_y3*_x1)/2;
    }
    double perimeter() const{
        vector<double> sides = getAllSides();
        double ret = 0;
        for (vector<double>::iterator it = sides.begin();
             it != sides.end(); ++it){
                ret += *it;
             }
        return ret;
    }
    bool isTriangle() {
        vector<double> sides = getAllSides();
        if ((sides[0]+sides[1] > sides[2]) &&
                (sides[1]+sides[2] > sides[0]) &&
                (sides[0]+sides[2] > sides[1]))
                return true;
        else{
            throw string("Not a triangle.");
        }
    }
    
private:
    vector<double> getAllSides() const{
        double a = getEdgeLength(_x1, _y1, _x2, _y2);
        double b = getEdgeLength(_x2, _y2, _x3, _y3);
        double c = getEdgeLength(_x1, _y1, _x3, _y3);
        vector<double> sides = {a, b, c};
        return sides;
    }
    double getEdgeLength(double _x1, double _y1,
                         double _x2, double _y2) const{
        return sqrt(pow(_x2-_x1, 2)+pow(_y2-_y1, 2));
    }
    double _x1, _x2, _x3;
    double _y1, _y2, _y3;
};
#endif // TRIANGLE_H
