#include <iostream>
#include <vector>
#include <string>
#include "processfile.h"
#include "parser.h"
#include "factory.h"
#include "shape.h"
#include "sort.h"
#include <vector>
using namespace std;
vector<Shape*>* getShapes(string filePath){
    ProcessFile* pf = new ProcessFile();
    vector<string>* lines = pf->readFile(filePath);
    vector<Shape*>* shapes = new vector<Shape*>();
    Factory* factory = new Factory();
    for (auto line: *lines){
        Parser parser = Parser(line);
        Shape* shape = factory->createShape(parser.getShapeName(), parser.getParams());
        shapes->push_back(shape);
    }
    return shapes;
}
// 不會OO
void sortShapes(vector<Shape*>* shapes, string orderBy, string arrange){
    Sort sort = Sort(&(*shapes));
    if (orderBy.compare("area") == 0){
        if (arrange.compare("inc") == 0) sort.sortArea([](const Shape* a, const Shape* b){ return a->area() < b->area(); });
        if (arrange.compare("dec") == 0) sort.sortArea([](const Shape* a, const Shape* b){ return a->area() > b->area(); });
    }
    if (orderBy.compare("perimeter") == 0){
        if (arrange.compare("dec") == 0) sort.sortPerimeter(perimeterDescendingComparison);
        if (arrange.compare("inc") == 0) sort.sortPerimeter(perimeterAscendingComparison);
    }
    if (orderBy.compare("compactness") == 0){
        if (arrange.compare("dec") == 0) sort.sortCompactness(CompactnessDescendingComparison());
        if (arrange.compare("inc") == 0) sort.sortCompactness(CompactnessAscendingComparison());
    }
}

void output(vector<Shape*>* shapes, string filePath, string orderBy){
    string outputLine = "[";
    ofstream myfile(filePath);
    if (myfile.is_open()){
        myfile << '[';
        for (size_t i = 0; i < shapes->size(); i++){
            if (orderBy.compare("area") == 0) myfile << (*shapes)[i]->area();
            else if (orderBy.compare("perimeter") == 0) myfile << (*shapes)[i]->perimeter();
            else if (orderBy.compare("compactness") == 0) myfile << (*shapes)[i]->compactness();
            if (i < shapes->size()-1) myfile << ",";
        }
        myfile << ']';
    }
    myfile.close();
}

// 傷眼抱歉
int main(int argc, char *argv[])
{
    vector<string> all_args;
    if (argc == 5){
        // argv[0] == exe_name
        all_args.assign(argv+1, argv + argc);
    }
    cout << all_args[0] << ' ' << all_args[1] << ' ' << all_args[2] << endl;
    vector<Shape*>* shapes = getShapes(all_args[0]);
    sortShapes(shapes, all_args[2], all_args[3]);
    output(shapes, all_args[1], all_args[2]);
}