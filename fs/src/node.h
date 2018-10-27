#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include <string>
class SizeVisitor;
class Node
{
  public:
    Node(const char *path) : _path(path)
    {
        _is_alive = lstat(_path, &_st);
    }

    int size() const
    {
        return _st.st_size;
    }

    virtual void accept(SizeVisitor* v) = 0;

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

    virtual std::string find(std::string nodeName) const = 0;
    virtual std::string findPath(std::string nodeName) const = 0;
    virtual std::string getPath() const{
        return _path;
    }
  private:
    const char *_path;
    struct stat _st;
    bool _is_alive;
};

#endif
