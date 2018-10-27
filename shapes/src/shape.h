#if !defined(SHAPE)
#define SHAPE
#include <cmath>

class Shape {
    public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual double compactness() {
            if(this->area() == 0){
                throw std::string("Division by zero");
            }
            return pow(this->perimeter(), 2)/this->area();
        }
};
#endif // SHAPE


