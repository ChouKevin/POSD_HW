#ifndef SHAPE_H
#define SHAPE_H
class FindAreaVisitor;
class Shape
{
public:
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual void accept(FindAreaVisitor* fav);
  virtual Shape* getChild(int index);
  virtual int numberOfChild();
};
#endif