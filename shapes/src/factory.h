
#if !defined(FACTORY_H)
#define FACTORY_H

#include "rectangle.h"
#include "circle.h"
#include "shape.h"
#include "triangle.h"
#include <vector>
#include <string>

using namespace std;
class Factory{
    public:
        Factory(){
        }
        Shape* createShape(string shapeName, vector<double> params){
            Shape* shape;
            if (!shapeName.compare("Circle")){
                shape = new Circle(params.at(0));
            }
            else if(!shapeName.compare("Rectangle")){
                shape = new Rectangle(params.at(0), params.at(1));
            }
            else if(!shapeName.compare("Triangle")){
                shape = new Triangle(params.at(0), params.at(1),
                                            params.at(2), params.at(3),
                                            params.at(4), params.at(5));
            }
            return shape;
        }
};


#endif // FACTORY_H
