#if !defined(VISITOR)
#define VISITOR

class File;
class Folder;

class IVisitor{
    public:
        virtual void visit(File* file) = 0;
        virtual void visit(Folder* folder) = 0;
};

class SizeVisitor: public IVisitor{
    public:
        SizeVisitor();
        void visit(File* file);
        void visit(Folder* folder);
        int getSize() const;
    private:
        int _size;
};
#endif // VISITOR
