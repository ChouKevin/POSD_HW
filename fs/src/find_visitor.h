#if !defined(FIND_VISITOR_H)
#define FIND_VISITOR_H

#include <string>
#include "node_visitor.h"
#include <vector>
using namespace std;
class File;
class Folder;
class Node;
class FindVisitor : public NodeVisitor
{
  public:
    FindVisitor(string nodeName);
    void visitFile(File *file);
    void visitFolder(Folder *folder);
    string findResult();
    void concatResult(string currentNode, vector<string> childNode);
  private:
    string _nodeName;
    vector<string> _path;
    bool isFile = false;
};
#endif // FIND_VISITOR_H
