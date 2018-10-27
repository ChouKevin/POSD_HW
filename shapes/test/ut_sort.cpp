#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/sort.h"

TEST(SortTest, sortAreaByDES){
    vector<Shape*> shpaes = {new Rectangle(1, 10), new Rectangle(1, 3), new Rectangle(1, 4)};
    Sort s = Sort(&shpaes);
    s.sortArea([](const Shape* a, const Shape* b){ return a->area() > b->area(); });
    ASSERT_EQ(shpaes[0]->area(), 10);
}

TEST(SortTest, sortAreaByASC){
    vector<Shape*> shpaes = {new Rectangle(1, 10), new Rectangle(1, 3), new Rectangle(1, 4)};
    Sort s = Sort(&shpaes);
    s.sortArea([](const Shape* a, const Shape* b){ return a->area() < b->area(); });
    ASSERT_EQ(shpaes[0]->area(), 3);
}

TEST(SortTest, sortPerimeterByDES){
    vector<Shape*> shpaes = {new Rectangle(1, 10), new Rectangle(1, 3), new Rectangle(1, 4)};
    Sort s = Sort(&shpaes);
    s.sortPerimeter(perimeterDescendingComparison);
    ASSERT_EQ(shpaes[0]->area(), 10);
}

TEST(SortTest, sortPerimeterByASC){
    vector<Shape*> shpaes = {new Rectangle(1, 10), new Rectangle(1, 3), new Rectangle(1, 4)};
    Sort s = Sort(&shpaes);
    s.sortPerimeter(perimeterAscendingComparison);
    ASSERT_EQ(shpaes[0]->area(), 3);
}

TEST(SortTest, sortCompactnessByDES){
    vector<Shape*> shpaes = {new Rectangle(1, 10), new Rectangle(1, 3), new Rectangle(1, 4)};
    Sort s = Sort(&shpaes);
    s.sortPerimeter(CompactnessDescendingComparison());
    ASSERT_EQ(shpaes[0]->area(), 10);
}

TEST(SortTest, sortCompactnessByASC){
    vector<Shape*> shpaes = {new Rectangle(1, 10), new Rectangle(1, 3), new Rectangle(1, 4)};
    Sort s = Sort(&shpaes);
    s.sortPerimeter(CompactnessAscendingComparison());
    ASSERT_EQ(shpaes[0]->area(), 3);
}