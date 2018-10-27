#include "visitor.h"
#include "file.h"
#include "folder.h"
SizeVisitor::SizeVisitor(): _size(0){};

void SizeVisitor::visit(File* file){
    this->_size += file->size();
}

void SizeVisitor::visit(Folder* folder){
    for (auto node : folder->_children){
        node->accept(this);
    }
}

int SizeVisitor::getSize() const{
    return this->_size; 
}