#include "shape.h"
#include "find_area_visitor.h"

void Shape::accept(FindAreaVisitor* fav){
    if (this->numberOfChild() > 0)
        fav->visit(this);
}

Shape* Shape::getChild(int index){
    return nullptr;
}

int Shape::numberOfChild(){
    return 0;
}