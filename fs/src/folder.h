#if !defined(FOLDER_H)
#define FOLDER_H

#include "node.h"
#include <map>
#include "node_visitor.h"
#include "node_iterator.h"
#include <string>
class Folder : public Node
{
  public:
    class FolderIterator : public NodeIterator
    {
      public:
        FolderIterator(Folder *f) : _folder(f) {}
        void first()
        {
            this->_it = this->_folder->_children.begin();
        }
        void next()
        {
            if (this->isDone())
                throw std::string("moving past the end");
            this->_it++;
        }
        Node* currentItem()
        {
            if (isDone())
                throw std::string("no currnet item");
            return this->_it->second;
        }
        bool isDone()
        {
            return this->_it == this->_folder->_children.end();
        }

      private:
        Folder *_folder;
        std::map<std::string, Node *>::iterator _it;
    };
    Folder(const char *path) : Node(path)
    {
    }

    void add(Node *node)
    {
        _children.insert(std::pair<std::string, Node*>(node->name(), node));
    }

    void accept(NodeVisitor *v)
    {
        v->visitFolder(this);
    }

    int numberOfChildren() const
    {
        return _children.size();
    }

    NodeIterator* createIterator()
    {
        return new FolderIterator(this);
    }

  private: 
    std::map<std::string, Node *> _children;
};

#endif // FOLDER
