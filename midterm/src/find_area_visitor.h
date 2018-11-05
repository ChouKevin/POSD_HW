#ifndef FIND_AREA_VISITOR_H
#define FIND_AREA_VISITOR_H

#include <vector>
class Circle;
class Rectangle;
class Ellipse;
class ComplexShapes;
class Shape;
class FindAreaVisitor {
public:
    FindAreaVisitor(double min, double max);
    void visit(Circle* shape);
    void visit(Rectangle* shape);
    void visit(Ellipse* shape);
    void visit(ComplexShapes* shape);
    void visit(Shape* shape);
    void init();
    std::vector<Shape*> findResult();
private:
    double _min, _max;
    std::vector<Shape*> _result;
};
#endif