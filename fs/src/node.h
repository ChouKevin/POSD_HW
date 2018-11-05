#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include <string>
#include <sstream>
class NodeVisitor;
class NodeIterator;
class Node
{
  public:
    Node(const char *path) : _path(path)
    {
        lstat(_path, &_st);
    }

    int size() const
    {
        return _st.st_size;
    }

    virtual void accept(NodeVisitor* v) = 0;
    virtual NodeIterator* createIterator() = 0;

    virtual void add(Node *node)
    {
        throw std::string("unable to add");
    }

    virtual int numberOfChildren() const
    {
        throw std::string("number of children: not applicable");
    }

    virtual std::string name() const
    {
        std::string fileName;
        std::istringstream ss(this->_path);
        while (std::getline(ss, fileName, '/')){
        }
        return fileName;
    }

    virtual std::string getPath() const{
        return _path;
    }
  private:
    const char *_path;
    struct stat _st;
};

#endif
