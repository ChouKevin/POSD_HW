#include "find_visitor.h"
#include "file.h"
#include "folder.h"
#include "node_iterator.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
FindVisitor::FindVisitor(string nodeName) : _path({}), _nodeName(nodeName){};

void FindVisitor::visitFile(File *file)
{
    this->isFile = true;
    this->_path.clear();
    if (file->name().compare(this->_nodeName) == 0)
        this->_path.push_back(file->name());
}
void FindVisitor::visitFolder(Folder *folder)
{
    NodeIterator * it = folder->createIterator();
    this->_path.clear();
    for (it->first(); !it->isDone(); it->next())
    {
        FindVisitor* newVisitor = new FindVisitor(this->_nodeName);
        it->currentItem()->accept(newVisitor);
        // number of children >=0 must be a folder
        if (it->currentItem()->numberOfChildren() >= 0){
            if (it->currentItem()->name().compare(this->_nodeName) == 0)
                this->_path.push_back(it->currentItem()->name());
            this->concatResult(it->currentItem()->name(), newVisitor->_path);
        }
        else
            this->concatResult("", newVisitor->_path);
        delete newVisitor;
    }
}
void FindVisitor::concatResult(string currentNode, vector<string> childNode){
    std::string ret = "";
    bool isMoreThenOne = false;
    for (auto node : childNode){
        if (!currentNode.empty())
            this->_path.push_back(currentNode+'/'+node);
        else
            this->_path.push_back(node);
    }
}
string FindVisitor::findResult()
{
    string ret = "";
    bool isMoreThanOne = false;
    for (auto path : this->_path)
    {
        if (isMoreThanOne)
            ret += "\n";
        else
            isMoreThanOne = true;
        if (isFile)
            ret += path;
        else
            ret += "./"+path;
    }
    return ret;
}