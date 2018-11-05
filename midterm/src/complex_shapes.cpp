#include "complex_shapes.h"
#include "shape.h"
#include <vector>
#include "find_area_visitor.h"
#include <iostream>
ComplexShapes::ComplexShapes(std::vector<Shape*>* shapes){
    this->_shapes = shapes;
    std::cout << "ComplexShapes:" << this->area() << std::endl; 
}

double ComplexShapes::area() const{
    double ret = 0;
    for (auto shape : *(this->_shapes)){
        ret += shape->area();
    }
    return ret;
}

double ComplexShapes::perimeter() const{
    double ret = 0;
    for (auto shape : *(this->_shapes)){
        ret += shape->perimeter();
    }
    return ret;
}

void ComplexShapes::accept(FindAreaVisitor* fav){
    fav->init();
    fav->visit(this);
}

void ComplexShapes::add(Shape* s){
    this->_shapes->push_back(s);
}

Shape* ComplexShapes::getChild(int index){
    return this->_shapes->at(index);
}

int ComplexShapes::numberOfChild(){
    return this->_shapes->size();
}