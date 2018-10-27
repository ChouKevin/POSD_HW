#ifndef UT_FS_H
#define UT_FS_H

#include <sys/stat.h>
#include "../src/folder.h"
#include "../src/file.h"
#include "../src/visitor.h"
#include <sstream>
TEST (MiscTest, lstatOnFolder)
{
  const char * path = "./test_data";
  struct stat st;
  ASSERT_EQ(0, lstat(path, &st));
  // ASSERT_EQ(128, st.st_size);
  ASSERT_EQ(true, S_ISDIR(st.st_mode));
  ASSERT_EQ(false, S_ISREG(st.st_mode));
  ASSERT_EQ(false, S_ISLNK(st.st_mode));
}

TEST (FileSystemTest, SIZE)
{
  Node * test_data = new Folder ("./test_data");
  ASSERT_EQ(512,test_data->size());
  Node * folder = new Folder("./test_data/folder");
  ASSERT_EQ(512, folder->size());
  Node * hello_cpp = new File("./test_data/hello.cpp");
  ASSERT_EQ(87, hello_cpp->size());
  Node * a_out = new File("./test_data/folder/a.out");
  ASSERT_EQ(8432, a_out->size());
  test_data->add(folder);
  test_data->add(hello_cpp);
  ASSERT_EQ(2,test_data->numberOfChildren());
}
TEST (PRACTICE, VISITOR){
  File * a_out = new File("./test_data/folder/a.out");
  SizeVisitor * icv = new SizeVisitor();
  a_out->accept(icv);
  ASSERT_EQ(8432, icv->getSize());
}
#endif
