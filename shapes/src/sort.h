#if !defined(SORT_H)
#define SORT_H

#include <vector>
#include "shape.h"
#include <algorithm>
#include <stdexcept>
using namespace std;
class Sort
{
public:
    Sort(vector<Shape*>* v): _v(v) {};
    template<typename T>
    void sortArea(T comp){
        sort(_v->begin(), _v->end(), comp);
    }
    template<typename T>
    void sortPerimeter(T comp){
        sort(_v->begin(), _v->end(), comp);
    }
    template<typename T>
    void sortCompactness(T comp){
        sort(_v->begin(), _v->end(), comp);
    }
private:
    vector<Shape*>* _v;
};

bool perimeterDescendingComparison(Shape *a, Shape *b){
    return a->perimeter() > b->perimeter();
};

bool perimeterAscendingComparison(Shape *a, Shape *b){
    return a->perimeter() < b->perimeter();
};

class CompactnessAscendingComparison{
    public:
        bool operator() (Shape *a, Shape *b) {
            return a->compactness() < b->compactness();
        }
};

class CompactnessDescendingComparison{
    public:
        bool operator() (Shape *a, Shape *b) {
            return a->compactness() > b->compactness();
        }
};

#endif // SORT_H


