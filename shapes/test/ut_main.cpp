#include <gtest/gtest.h>
#include "ut_shape.cpp"
#include "ut_sort.cpp"
#include "ut_parser.cpp"
#include "ut_factory.cpp"
#include "ut_processfile.cpp"
int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
