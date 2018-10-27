#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
TEST(ShapeTest, first)
{
    ASSERT_TRUE(true);
}

TEST(ShapeTest, Circle)
{
    Circle c(10.0);
    ASSERT_NEAR(314.159, c.area(), 0.001);
    ASSERT_NEAR(62.831, c.perimeter(), 0.001);
}

TEST(ShapeTest, Rectangle)
{
    Rectangle rect(10.0, 5);
    ASSERT_NEAR(50, rect.area(), 0);
    ASSERT_NEAR(30, rect.perimeter(), 0);
}

TEST(ShapeTest, isTriangle)
{
    try{
        Triangle tri(1, 0, 1, 1, 1, 2);
        ASSERT_FALSE(tri.isTriangle());
    }
    catch(std::string e){
        ASSERT_EQ(e, "Not a triangle.");
    }
}

TEST(ShapeTest, Triangle)
{
    Triangle tri(0, 0, 3, 0, 0, 4);
    ASSERT_NEAR(6, tri.area(), 0);
    ASSERT_NEAR(12, tri.perimeter(), 0);
}

TEST(ShapeTest, Compactness)
{
    try
    {
        Shape* shape = new Rectangle(1, 0);
        ASSERT_EQ(shape->compactness(), 10);
    }
    catch (std::string e)
    {
        ASSERT_EQ(e, "Division by zero");
    }
}