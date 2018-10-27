#ifndef FILE_H
#define FILE_H

#include "node.h"
#include <string>
#include "visitor.h"
class File: public Node{
public:
  File(const char * path): Node(path)
  {

  }
  std::string find(std::string nodeName) const {
    if(this->name().compare(nodeName) == 0) return nodeName;
    return "";
  }
  std::string findPath(std::string nodeName) const{
    if(this->name().compare(nodeName) == 0) return this->getPath();
    return "";
  }

  void accept(SizeVisitor* v){
    v->visit(this);
  }
};

#endif
