#ifndef FILE_H
#define FILE_H

#include "node.h"
#include <string>
#include "node_visitor.h"
#include "node_iterator.h"
#include "null_iterator.h"
class File : public Node
{
  public:
    File(const char *path) : Node(path)
    {
    }

    int numberOfChildren() const
    {
        return -1;
    }

    void accept(NodeVisitor* v) {
        v->visitFile(this);
    }

    NodeIterator* createIterator(){
        return new NullIterator(this);
    }
};

#endif
