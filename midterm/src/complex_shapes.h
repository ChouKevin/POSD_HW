#ifndef COMPLEX_SHAPES_H
#define COMPLEX_SHAPES_H
#include <vector>
#include "shape.h"
class ComplexShapes: public Shape
{
public:
    ComplexShapes(std::vector<Shape*>* shape);
    double area() const ;
    double perimeter() const;
    void add(Shape *s);
    Shape* getChild(int index);
    int numberOfChild();
    void accept(FindAreaVisitor* fav);
private:
    std::vector<Shape*>* _shapes;
};


#endif