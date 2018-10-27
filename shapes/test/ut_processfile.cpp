#include <gtest/gtest.h>
#include "../src/processfile.h"
#include <string>
#include <fstream>
using namespace std;
TEST(ProcessFileTest, first)
{
    ASSERT_TRUE(true);
    fstream myfile("input.txt");
    ASSERT_TRUE(myfile.is_open());
}

TEST(ProcessFileTest, readFile){
    ProcessFile pf = ProcessFile();
    vector<string>* lines = pf.readFile("input.txt");
    ASSERT_EQ(lines->size(), 3);
    ASSERT_FALSE(lines->at(0).compare("Circle (1.5)"));
}