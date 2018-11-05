#if !defined(VISITOR_H)
#define VISITOR_H
#include <vector>
#include <string>
using namespace std;
class File;
class Folder;

class NodeVisitor{
    public:
        virtual void visitFile(File* file) = 0;
        virtual void visitFolder(Folder* folder) = 0;
};
#endif // VISITOR
