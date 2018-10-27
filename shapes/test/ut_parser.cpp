#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/parser.h"
#include <string>

using namespace std;
TEST(ParserTest, first)
{
    ASSERT_TRUE(true);
}

TEST(ParserTest, splite){
    string input = "Circle (1.5)";
    Parser parser = Parser(input);
    vector<string> splited = parser.splite("Circle (1.5)");
    ASSERT_EQ(splited.at(1), "(1.5)");
    ASSERT_EQ(splited.at(0), "Circle");
}
TEST(ParserTest, getParams){
    string input = "Rectangle (1.5,1.6)";
    Parser parser = Parser(input);
    vector<double> params = parser.getParams();
    ASSERT_EQ(params[0], 1.5);
    ASSERT_EQ(params[1], 1.6);
}
// TEST(ParserTest, getShape){
//     string input = "Circle (1.5)";
//     Parser parser = Parser(input);
//     Shape* shape = parser.getShape();
//     ASSERT_NEAR(shape->area(), M_PI * 1.5 * 1.5, 0.001);
// }