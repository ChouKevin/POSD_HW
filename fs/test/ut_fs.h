#ifndef UT_FS_H
#define UT_FS_H

#include <sys/stat.h>
#include "../src/folder.h"
#include "../src/file.h"
#include "../src/info_content_visitor.h"
#include "../src/find_visitor.h"
#include "../src/null_iterator.h"
#include <sstream>
TEST(MiscTest, lstatOnFolder)
{
    const char *path = "./test_data";
    struct stat st;
    ASSERT_EQ(0, lstat(path, &st));
    // ASSERT_EQ(128, st.st_size);
    ASSERT_EQ(true, S_ISDIR(st.st_mode));
    ASSERT_EQ(false, S_ISREG(st.st_mode));
    ASSERT_EQ(false, S_ISLNK(st.st_mode));
}

TEST(FileSystemTest, SIZE)
{
    Node *test_data = new Folder("./test_data");
    // ASSERT_EQ(4096, test_data->size());
    Node *folder = new Folder("./test_data/folder");
    // ASSERT_EQ(4096, folder->size());
    Node *hello_cpp = new File("./test_data/hello.cpp");
    // ASSERT_EQ(87, hello_cpp->size());
    Node *a_out = new File("./test_data/folder/a.out");
    // ASSERT_EQ(8432, a_out->size());
    test_data->add(folder);
    test_data->add(hello_cpp);
    ASSERT_EQ(2, test_data->numberOfChildren());
}
TEST(PRACTICE, VisitFileSize)
{
    File *a_out = new File("./test_data/folder/a.out");
    InfoContentVisitor *icv = new InfoContentVisitor();
    a_out->accept(icv);
    // ASSERT_EQ(8432, icv->getContentSize());
    ASSERT_EQ(-1, a_out->numberOfChildren());
}
TEST(PRACTICE, VisitFolderSize)
{
    InfoContentVisitor* icv = new InfoContentVisitor();
    Node *folder = new Folder("./test_data/folder");
    File *a_out = new File("./test_data/folder/a.out");
    folder->accept(icv);
    // ASSERT_EQ(0, icv->getContentSize());
    folder->add(a_out);
    folder->accept(icv);
    // ASSERT_EQ(8432, icv->getContentSize());
    ASSERT_EQ(1, folder->numberOfChildren());
}

TEST(PRACTICE, VisitFilePath)
{
    FindVisitor* icv = new FindVisitor("a.out");
    Node *file = new File("./test_data/a.out");
    file->accept(icv);
    ASSERT_EQ("a.out", icv->findResult());
}

TEST(PARCTICE, VisitFolderPath){
    FindVisitor* icv = new FindVisitor("test_data");
    Node *folder = new Folder("./test_data");
    folder->accept(icv);
    ASSERT_EQ("", icv->findResult());
}
TEST(PARCTICE, VisitFilePathInFolder){
    FindVisitor* icv = new FindVisitor("a.out");
    Node* folder = new Folder("./test_data");
    Node* file = new File("./test_data/a.out");
    folder->add(file);
    folder->accept(icv);
    ASSERT_EQ("./a.out", icv->findResult());
}
TEST(PARCTICE, VisitFilePathInFolderAndSecondFolder){
    FindVisitor* icv = new FindVisitor("a.out");
    Node* folder = new Folder("./test_data");
    Node* folder2 = new Folder("./test_data/folder");
    Node* file = new File("./test_data/a.out");
    Node* file2 = new File("./test_data/folder/a.out");
    folder->add(file);
    folder->add(folder2);
    folder2->add(file2);
    folder->accept(icv);
    ASSERT_EQ("./a.out\n./folder/a.out", icv->findResult());
}
TEST(PARCTICE, VisitFilePathInSecondFolder){
    FindVisitor* icv = new FindVisitor("a.out");
    Node* folder = new Folder("./test_data");
    Node* folder2 = new Folder("./test_data/folder");
    Node* file = new File("./test_data/folder/a.out");
    folder->add(folder2);
    folder2->add(file);
    ASSERT_EQ(1, folder2->numberOfChildren());
    folder->accept(icv);
    ASSERT_EQ("./folder/a.out", icv->findResult());
}
TEST(PARCTICE, VisitEmptyFolderInFolder){
    FindVisitor* icv = new FindVisitor("a.out");
    Node* folder = new Folder("./test_data");
    Node* folder2 = new Folder("./test_data/folder");
    folder->add(folder2);
    ASSERT_EQ(0, folder2->numberOfChildren());
    folder->accept(icv);
    ASSERT_EQ("", icv->findResult());
}
TEST(PARCTICE, VisitEmptyFolderInSecondFolder){
    FindVisitor* icv = new FindVisitor("a.out");
    Node* folder = new Folder("./test_data");
    Node* folder2 = new Folder("./test_data/folder");
    Node* folder3 = new Folder("./test_data/folder/folder3");
    folder->add(folder2);
    folder2->add(folder3);
    ASSERT_EQ(1, folder2->numberOfChildren());
    ASSERT_EQ(0, folder3->numberOfChildren());
    folder->accept(icv);
    ASSERT_EQ("", icv->findResult());
}
TEST(PARCTICE, VisitFolderPathInSecondFolder){
    FindVisitor* icv = new FindVisitor("folder");
    Node* folder = new Folder("./test_data");
    Node* folder2 = new Folder("./test_data/folder");
    folder->add(folder2);
    ASSERT_EQ(0, folder2->numberOfChildren());
    folder->accept(icv);
    ASSERT_EQ("./folder", icv->findResult());
}
TEST(PARCTICE, VisitNotExistFile){
    FindVisitor* icv = new FindVisitor("b.out");
    Node* file = new File("./test_data/a.out");
    file->accept(icv);
    ASSERT_EQ("", icv->findResult());
}
TEST(PARCTICE, VisitExistFile){
    FindVisitor* icv = new FindVisitor("a.out");
    Node* folder = new Folder("./test_data");
    Node* file = new File("./test_data/a.out");
    folder->add(file);
    folder->accept(icv);
    ASSERT_EQ("./a.out", icv->findResult());
    file->accept(icv);
    ASSERT_EQ("a.out", icv->findResult());
}
TEST(PARCTICE, VisitNotExistFileInFolder){
    FindVisitor* icv = new FindVisitor("b.out");
    Node* folder = new Folder("./test_data");
    Node* folder2 = new Folder("./test_data/folder");
    Node* file = new File("./test_data/a.out");
    Node* file2 = new File("./test_data/folder/a.out");
    folder->add(file);
    folder->add(folder2);
    folder2->add(file2);
    folder->accept(icv);
    ASSERT_EQ("", icv->findResult());
}

TEST(PARCTICE, ReuseVisitor){
    FindVisitor* icv = new FindVisitor("a.out");
    Node* folder = new Folder("./test_data");
    Node* folder2 = new Folder("./test_data/folder");
    Node* file = new File("./test_data/folder/a.out");
    folder->add(folder2);
    folder2->add(file);
    folder->accept(icv);
    ASSERT_EQ("./folder/a.out", icv->findResult());
    folder2->accept(icv);
    ASSERT_EQ("./a.out", icv->findResult());
}

// TEST()
#endif
