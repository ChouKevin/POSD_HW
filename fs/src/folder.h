#if !defined(FOLDER)
#define FOLDER

#include "node.h"
#include <vector>
#include "visitor.h"
#include <iostream>
#include <sstream>
class Folder : public Node
{
    friend SizeVisitor;

  public:
    Folder(const char *path) : Node(path)
    {
    }

    void add(Node *node)
    {
        _children.push_back(node);
    }

    void accept(SizeVisitor* v){
        v->visit(this);
    }

    int numberOfChildren() const
    {
        return _children.size();
    }

    std::string findPath(std::string nodeName) const
    {
        std::string filePath = "";
        for (auto const &node : this->_children)
        {
            if (node->name().compare(nodeName) == 0)
            {
                std::cout << "by node name : " << node->getPath() << std::endl;
                filePath += node->getPath() + " ";
            }
            std::string path = node->findPath(nodeName);
            if (!path.empty() && path.compare(node->getPath()) != 0)
            {
                std::cout << "by find path : " << path << std::endl;
                filePath += path + " ";
            }
        }
        return filePath;
    }
    std::string find(std::string nodeName) const
    {
        std::string totalPath = this->findPath(nodeName);
        std::cout << "result : " << totalPath << std::endl;
        return this->concatPath(this->findPath(nodeName));
    }

  private:
    std::string concatPath(std::string filePath) const
    {
        std::istringstream ss(filePath);
        std::string token;
        std::string result;
        bool isMoreThenOne = false;
        while (std::getline(ss, token, ' '))
        {
            size_t pos = token.find(this->getPath());
            if (pos != std::string::npos)
            {
                token.erase(pos, this->getPath().length());
                if (isMoreThenOne)
                    result += "\n";
                else
                    isMoreThenOne = true;
                result += "." + token;
            }
        }
        return result;
    }
    std::vector<Node *> _children;
};

#endif // FOLDER
