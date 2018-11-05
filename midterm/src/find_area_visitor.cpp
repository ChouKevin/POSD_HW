#include "find_area_visitor.h"
#include <vector>
#include "shape.h"
#include "circle.h"
#include "ellipse.h"
#include "rectangle.h"
#include "complex_shapes.h"
#include <iostream>
FindAreaVisitor::FindAreaVisitor(double min, double max){
    this->_max = max;
    this->_min = min;
}

void FindAreaVisitor::visit(Circle* shape){
    if (shape->area() <= this->_max && shape->area() >= _min){
        this->_result.push_back(shape);
    }
}
void FindAreaVisitor::visit(Rectangle* shape){
    if (shape->area() <= this->_max && shape->area() >= _min){
        this->_result.push_back(shape);
    }
}
void FindAreaVisitor::visit(Ellipse* shape){
    if (shape->area() <= this->_max && shape->area() >= _min){
        this->_result.push_back(shape);
    }
}
void FindAreaVisitor::visit(Shape* shape){
    if (shape->area() <= this->_max && shape->area() >= _min){
        this->_result.push_back(shape);
    }
}
void FindAreaVisitor::visit(ComplexShapes* shape){
    // for (int i = 0; i < shape->numberOfChild(); i++){
    //     ComplexShapes* tmp = dynamic_cast<ComplexShapes*>(shape->getChild(i));
    //     if (tmp){
    //         // std::cout << "is complexshape" << std::endl;
    //         this->visit(shape->getChild(i));
    //         this->visit(tmp);
    //     }
    //     else{
    //         this->visit(shape->getChild(i));
    //     }
    // }
    for (int i = 0; i < shape->numberOfChild(); i++){
        ComplexShapes* tmp = dynamic_cast<ComplexShapes*>(shape->getChild(i));
        if (tmp){
            this->visit(shape->getChild(i));
            this->visit(tmp);
        }
        else{
            this->visit(shape->getChild(i));
        }
    }
}

void FindAreaVisitor::init(){
    this->_result.clear();
}

std::vector<Shape*> FindAreaVisitor::findResult(){
    return this->_result;
}