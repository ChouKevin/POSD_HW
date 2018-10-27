#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/parser.h"
#include "../src/factory.h"
#include <string>

using namespace std;

TEST(FactoryTest, first){
    ASSERT_TRUE(true);
}

TEST(FactoryTest, getCircle){
    vector<double> params = {1.5};
    ASSERT_EQ(params[0], 1.5);
    Factory factory = Factory();
    Shape* shape = factory.createShape("Circle", params);
    ASSERT_NEAR(shape->area(), M_PI*1.5*1.5, 0.001);
}

TEST(FactoryTest, getRectangle){
    vector<double> params = {2,3};
    ASSERT_EQ(params[0], 2);
    ASSERT_EQ(params[1], 3);
    Factory factory = Factory();
    Shape* shape = factory.createShape("Rectangle", params);
    ASSERT_NEAR(shape->area(), 6, 0.001);
}
TEST(FactoryTest, getTriangle){
    vector<double> params = {0,0,1,1,2,0};
    Factory factory = Factory();
    Shape* shape = factory.createShape("Triangle", params);
    ASSERT_NEAR(shape->area(), 1, 0.001);
}